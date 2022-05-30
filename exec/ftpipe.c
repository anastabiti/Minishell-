/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/30 09:34:48 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



int ft_pipe(struct s_list *list)

{
			list->there_is_pipe = 0;

		if (list->there_is_pipe == 0)
		{
			if (ft_is_built_in(list) == 0)
			{
				ft_bin_usr_sbin(list->input);
			}
		}
if (list->there_is_pipe > 0)
		{
			int i = 0;
			int fd_in = 0;
			int fd[2];
			while (i < list->there_is_pipe + 1)
			{
				pipe(fd);
				if (fork() == 0)
				{
					dup2(fd_in, 0);
					if (i < list->there_is_pipe)
						dup2(fd[1], 1);
					close(fd[0]);
					// if (i == 0)
					// {
					// 	ft_pwd(fd[1]);
					// 	return 0;
					// }
					// if (i > 0)
				
					
									execve(list[i].cmd[0], list[i].cmd, NULL);
					printf("FAILED \n");
					
				}
				else
				{
					wait(NULL);
					list->fd_out = fd[1];
					close(fd[1]);
					fd_in = fd[0];
				
					i++;
				}
			}
		}
	return 0;
}