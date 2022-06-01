/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/01 09:31:47 by atabiti          ###   ########.fr       */
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
		while (i < list->cmd_nbr)
		{
			if (i == 0)
			{
			
				ft_is_built_in(list);
				i++;
			}

			while (i < list->cmd_nbr)
			{
				pipe(fd);

				id = fork();
				// if (i == 0)
				// {

				// 	list->fd_out = fd[1];
				// 	ft_is_built_in(list);
				// 	i++;
				// }
				if (id == 0)
				{

					dup2(fd_in, 0);
					if (i < list->there_is_pipe)

						dup2(fd[1], 1);

					close(fd[0]);

					if (execve(list[i].cmd[0], list[i].cmd, NULL) == -1)
					{
						printf("failed\n");
						return 0;
					}
				}

				if (id > 0)
				{

					list->fd_out = fd[1];
					close(fd[1]);
					// close(fd[0]);

					wait(NULL);

					fd_in = fd[0];

					i++;
				}
			}

			i++;
		}
	}
	return 0;
}