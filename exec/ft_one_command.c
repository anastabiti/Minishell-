/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:40:08 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/22 09:09:22 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

int	one_cmd_1(struct s_list *list)
{
	int	i;

	i = 0;
	if (fork() == 0)
	{
		redirections(list);
				// heredoc_without_cmd(list);

		while (list[0].type[i] != NULL)
		{
			if (ft_strncmp(list[0].type[i], HEREDOC, 7) == 0)
				dup2(list->fd_in, 0);
			if (ft_strncmp(list[0].type[i], RDOUT, 7) == 0)
				dup2(list->fd_out, 1);
			if (ft_strncmp(list[0].type[i], RDIN, 6) == 0)
				dup2(list->fd_in, 0);
			if (ft_strncmp(list[0].type[i], RDOUT, 7) == 0)
				close(list->fd_out);
			if (ft_strncmp(list[0].type[i], RDIN, 6) == 0)
				close(list->fd_in);
					if (ft_strncmp(list[0].type[i], HEREDOC, 7) == 0)
				close(list->fd_in);
			i++;
		}
		ft_bin_usr_sbin(list);
	}
	return (0);
}

int	one_cmd(struct s_list *list)
{
	int	i;

	if (list->cmd_nbr == 1 && is_builtin(list, 0) == 0)
	{
		i = 0;
		redirections(list);
		ft_is_built_in(list);
		if (list[0].type[i] != NULL)
		{
			if (ft_strncmp(list[0].type[i], RDOUT, 7) == 0)
			{
				close(list->fd_out);
			}
			if (ft_strncmp(list[0].type[i], RDIN, 6) == 0)
			{
				close(list->fd_in);
			}
			if (ft_strncmp(list[0].type[i], RDAPPEND, 10) == 0)
			{
				close(list->fd_out);
			}
		}
		return (1);
	}
	else if (list->cmd_nbr == 1 && is_builtin(list, 0) == 3)
	{
		one_cmd_1(list);
		wait(&g_exit_status);
		return (1);
	}
	return (0);
}
