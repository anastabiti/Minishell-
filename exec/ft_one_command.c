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
		while(list[0].rd[i].type != NULL)
		{

		
		if (ft_strncmp(list[0].rd[i].type , RDOUT, 7) == 0)
				dup2(list->fd_out, 1);
		if (ft_strncmp(list[0].rd[i].type , RDIN, 6) == 0)
				dup2(list->fd_in, 0);
				if (ft_strncmp(list[0].rd[i].type , RDOUT, 7) == 0)
			close(list->fd_out);
		if (ft_strncmp(list[0].rd[i].type , RDIN, 6) == 0)
			close(list->fd_in);
			i++;
		}
		ft_bin_usr_sbin(list);
		
	}

	return (0);
}

int	one_cmd(struct s_list *list)
{
	if (list->cmd_nbr == 1 && is_builtin(list, 0) == 0)
	{ int i = 0;
		redirections(list);
		ft_is_built_in(list);
		
		if (ft_strncmp(list[0].rd->type , RDOUT, 7) == 0)
		{
			close(list->fd_out);
		}
		if (ft_strncmp(list[0].rd->type , RDIN, 6) == 0)
		{
			close(list->fd_in);
		}
		if (ft_strncmp(list[0].rd->type , RDAPPEND, 10) == 0)
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
