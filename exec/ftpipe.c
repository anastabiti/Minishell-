/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/20 10:30:21 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
int	redire_2(struct s_list *list)
{
	int i = 0;
	int input;
	int output;
	int ret  = 0;
	while (list[list->cmd_iteration].type[i] != NULL)
	{
		// input = dup(0);
		// output = dup(1);
		if (ft_strncmp(list[list->cmd_iteration].type[i] , RDOUT, 7) == 0)
		{
			list->fd_out = open(list[list->cmd_iteration].file[i], O_RDWR | O_CREAT | O_TRUNC,
					0600);
			if (list->fd_out == -1)
			{
				printf("bash: No such file or directory\n");
			}
				ret = 1;

		}
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDIN, 6) == 0)
		{	
			list->fd_in = open(list[list->cmd_iteration].file[i], O_RDONLY, 0);
			if (list->fd_in == -1)
			{
				printf("bash: No such file or directory\n");
			}
				ret = 1;
		}
		if (ft_strncmp(list[list->cmd_iteration].type[i] , RDAPPEND, 10) == 0)
		{
			list->fd_out = open(list[list->cmd_iteration].file[i], O_RDWR | O_CREAT | O_APPEND, 0600);	
				ret = 1;
		}
		i++;
	}
	return (ret);
}
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
			redire_2(list);
			if(redire_2(list) == 1)
				dup2(list->fd[1], 1);
			set_rd(list);
			dup2(list->fd_in, 0);
			if (list->cmd_iteration < list->there_is_pipe)
				dup2(list->fd_out, 1);
			close(list->fd[0]);
			run_builtin(list);
		}
		else
		{
			wait(NULL);
			// list->fd_out = list->fd[1];
			close(list->fd[1]);
			list->fd_in = list->fd[0];
			list->cmd_iteration++;
		}
	}
}
