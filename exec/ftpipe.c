/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/14 11:25:15 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pipe(struct s_list *list)
{
	int i = 0;
	int id;
	int fd_in = 0;

	list->cmd_iteration = 0;

	while (list->cmd_iteration < list->cmd_nbr)
	{
		pipe(list->fd);
		id = fork();
		if (id == 0)
		{
			redirections(list);
			set_rd(list);
			dup2(fd_in, 0);
			if (list->cmd_iteration < list->there_is_pipe)
				dup2(list->fd[1], 1);
			close(list->fd[0]);
			run_builtin(list);
		}
		else
		{
			wait(NULL);
			list->fd_out = list->fd[1];
			close(list->fd[1]);
			fd_in = list->fd[0];
			list->cmd_iteration++;
		}
	}
}
