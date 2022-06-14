/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/14 09:14:28 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void	ft_pipe(struct s_list *list)
{
	int i = 0;
	int id;
	int fd_in = 0;
	int fd[2];

	list->cmd_iteration = 0;

	while (list->cmd_iteration < list->cmd_nbr)
	{
		pipe(fd);
		id = fork();
		redirections(list);

		if (id == 0)
		{
			if (list[list->cmd_iteration].REDIRECTION_OUT == 1)
				dup2(list->fd_out, 1);
			if (list[list->cmd_iteration].REDIRECTION_IN == 1)
				dup2(list->fd_in, 0);
			if (list[list->cmd_iteration].REDIRECTION_OUT == 1)
				close(list->fd_out);
			if (list[list->cmd_iteration].REDIRECTION_IN == 1)
				close(list->fd_in);

			dup2(fd_in, 0);
			if (list->cmd_iteration < list->there_is_pipe)

				dup2(fd[1], 1);

			close(fd[0]);

			if (ft_strncmp("echo", list[list->cmd_iteration].cmd[0], 4) == 0)
			{
				execve("builtins_bin/ftecho", list[list->cmd_iteration].cmd,
						list->environ);
				write(2, "sss", 3);
				exit(127);
			}
			else if (ft_strncmp("cd", list[list->cmd_iteration].cmd[0], 2) == 0)

			{
				if (execve("builtins_bin/ftcd", list[list->cmd_iteration].cmd,
						list->environ) == -1)
				{
					exit(31);
				}
			}
			else if (ft_strncmp("exit", list[list->cmd_iteration].cmd[0],
						4) == 0)

			{
				execve("builtins_bin/ftexit", list[list->cmd_iteration].cmd,
						list->environ);
				write(2, "sss", 3);
				exit(127);
			}
			else if (ft_strncmp("pwd", list[list->cmd_iteration].cmd[0],
						3) == 0)

			{
				execve("builtins_bin/ftpwd", list[list->cmd_iteration].cmd,
						list->environ);
				write(2, "sss", 3);
				exit(127);
			}
			else if (ft_strncmp("env", list[list->cmd_iteration].cmd[0],
						3) == 0)

			{
				execve("builtins_bin/ftenv", list[list->cmd_iteration].cmd,
						list->environ);
				write(2, "sss", 3);
				exit(127);
			}
			else if (ft_strncmp("unset", list[list->cmd_iteration].cmd[0],
						5) == 0)

			{
				execve("builtins_bin/ftunset", list[list->cmd_iteration].cmd,
						list->environ);
				write(2, "sss", 3);
				exit(127);
			}
			else if (ft_strncmp("export", list[list->cmd_iteration].cmd[0],
						6) == 0)

			{
				execve("builtins_bin/ftexport", list[list->cmd_iteration].cmd,
						list->environ);
				write(2, "sss", 3);
				exit(127);
			}

			else
			{
				ft_bin_usr_sbin(list);
			}
		
		}

		else
		{
			wait(NULL);

			list->fd_out = fd[1];

			close(fd[1]);

			fd_in = fd[0];

			list->cmd_iteration++;
		}
	}
}