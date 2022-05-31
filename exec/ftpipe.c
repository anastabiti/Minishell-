/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/31 11:50:28 by atabiti          ###   ########.fr       */
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

		while (i < list->there_is_pipe + 1)
		{
			pipe(fd);

			id = fork();
			if (id == 0)
			{
				dup2(fd_in, 0);
				if (i < list->there_is_pipe)
				
					dup2(fd[1], 1);
			
				close(fd[0]);

				if (execve(list[1].cmd[0], list[1].cmd, NULL) == -1)
				{
					printf("failed\n");
					return 0;
				}
			}

			else
			{
				list->fd_out = fd[1];
				ft_is_built_in(list);
				close(fd[1]);
				wait(NULL);

				fd_in = fd[0];

				i++;
			}
		}
	}
	return 0;
}