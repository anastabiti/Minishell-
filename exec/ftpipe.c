/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/28 08:46:48 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

// problem here
//&& redire_2(list) == 0 i must check previous redirection is not rdout
//  &&  ft_strncmp( list[0].type[1], RDOUT, 7) != 0 not workings
//check echo asd > f1 > f3 << f4
//ls > f1 > f2<< FF
int	redire_2(t_cmdl *list)
{
	int	i;
	int	input;
	int	output;
	int	ret;

	i = 0;
	ret = 0;
	while (list[list->cmd_iteration].type[i] != NULL)
	{
		if (ft_strncmp(list[0].type[i], HEREDOC, 7) == 0)
		{
			list->fd_in = open("f1", O_RDWR | O_CREAT | O_TRUNC, 0600);
		}
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDOUT, 7) == 0)
		{
			list->fd_out = open(list[list->cmd_iteration].file[i],
					O_RDWR | O_CREAT | O_TRUNC, 0600);
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
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDAPPEND, 10) == 0)
		{
			list->fd_out = open(list[list->cmd_iteration].file[i],
								O_RDWR | O_CREAT | O_APPEND,
								0600);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

void	ft_pipe(t_cmdl *list, struct						s_envp * envp)
{
	int	i;
	int	id;
	int	fd_in;

	i = 0;
	fd_in = 0;
	list->cmd_iteration = 0;
	while (list->cmd_iteration < list->cmd_nbr)
	{
		pipe(list->fd);
		id = fork();
		if (id == 0)
		{
			// redire_2(list);
			// set_rd(list);
			dup2(list->fd_in, 0);
			if ((list->cmd_iteration < list->there_is_pipe
					&& list[0].type[0] == NULL)
				|| (list->cmd_iteration < list->there_is_pipe
					&& ft_strncmp(list[0].type[0], RDOUT, 7) != 0))
				dup2(list->fd[1], 1);
			close(list->fd[0]);
			ft_is_built_in(list, envp);
			ft_bin_usr_sbin(list, envp);
			// run_builtin(list, envp);
		}
		else
		{
			wait(&g_exit_status);
			if (WIFEXITED(g_exit_status))
				g_exit_status = WEXITSTATUS(g_exit_status);
			close(list->fd[1]);
			list->fd_in = list->fd[0];
			list->cmd_iteration++;
		}
	}
}
