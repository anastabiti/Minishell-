/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 11:22:38 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_pipe(struct s_list *list)
{

	if (list->there_is_pipe > 0)
	{

		int i = 0;
		int id = 1;
		int fd_in = 0;
		int fd[2];
		// while (i < list->cmd_nbr)
		// {
		// if (i == 0)
		// {

		// 	ft_is_built_in(list);
		// 	i++;
		// }
		list->cmd_iteration = 0;

		while (list->cmd_iteration < list->cmd_nbr)
		{
			pipe(fd);
			id = fork();

			// if (ft_strncmp("cd", list[list->cmd_iteration].cmd[0], 2) == 0)
			// {
			// 	chdir(list->blt->cd_path);
			// }

			if (id == 0)
			{

				dup2(fd_in, 0);
				if (list->cmd_iteration < list->there_is_pipe)

					// close(1);
					dup2(fd[1], 1);

				close(fd[0]);
				// if (i == 0)
				// {
				if (ft_strncmp("echo", list[list->cmd_iteration].cmd[0], 4) == 0)
				{
					execve("builtins_bin/ftecho", list[list->cmd_iteration].cmd, list->environ);
					write(2, "sss", 3);
					exit(1);
				}
				else if (ft_strncmp("cd", list[list->cmd_iteration].cmd[0], 2) == 0)

				{
					execve("builtins_bin/ftcd", list[list->cmd_iteration].cmd, list->environ);
					write(2, "sss", 3);
					exit(1);
				}
				else
				{
					ft_bin_usr_sbin(list);
				}

				// }
				// if (execve(list[i].cmd[0], list[i].cmd, NULL) == -1)
				// {
				// 	// printf("command not found\n");
				// 	write(2, "MINISHELL command not found\n", 28);
				// 	exit(1);
				// }
			}

			else
			{

				wait(NULL);
				// if (list->cmd_iteration < list->there_is_pipe)
				// {
				list->fd_out = fd[1];
				// }
				// else
				// {
				// 	list->fd_out = 1;
				// }

				close(fd[1]);

				fd_in = fd[0];

				list->cmd_iteration++;
			}
		}

		// 	i++;
		// }
	}
	return 0;
}