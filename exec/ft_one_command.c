/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:40:08 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/14 11:44:29 by atabiti          ###   ########.fr       */
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
		while (list[i].next != NULL)
		{
			if (list[i].redirection_out == 1)
				dup2(list->fd_out, 1);
			if (list[i].redirection_in == 1)
				dup2(list->fd_in, 0);
			i++;
		}
		ft_bin_usr_sbin(list);
		if (list->redirection_out == 1)
			close(list->fd_out);
		if (list->redirection_in == 1)
			close(list->fd_in);
	}

	return (0);
}

int	one_cmd(struct s_list *list)
{
	if (list->cmd_nbr == 1 && is_builtin(list, 0) == 0)
	{
		redirections(list);
		ft_is_built_in(list);
		if (list->redirection_out == 1)
		{
			close(list->fd_out);
		}
		if (list->redirection_in == 1)
		{
			close(list->fd_in);
		}
			if (list->append_stdout == 1)
		{
			close(list->fd_out);
		}
		return (1);
	}
	else if (list->cmd_nbr == 1 && is_builtin(list, 0) == 3)
	{
		one_cmd_1(list);
		wait(NULL);
		return (1);
	}
    
	return (0);
}
