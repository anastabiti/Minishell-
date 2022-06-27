/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:36:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 10:44:46 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(t_cmdl *list, int i)
{
	if (list[i].cmd == NULL)
		return (0);
	if (ft_strncmp(list[i].cmd, "cd", 2) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd, "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd, "echo", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd, "env", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd, "exit", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd, "unset", 5) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd, "export", 6) == 0)
		return (0);
	return (3);
}

int	ft_is_built_in(t_cmdl *list, struct						s_envp * envp)
{
	int	i;

	i = 0;
	if (builtcheck(list, envp) == 1)
		return (1);
	else if (builtcheck_1(list, envp ) == 1)
		return (1);
	else if (ft_strncmp(list[0].cmd, "env", 3) == 0)
	{
		ft_env(envp, list);
		return (1);
	}
	else if (ft_strncmp(list[0].cmd, "pwd", 3) == 0)
	{
		ft_pwd(list->fd_out);
		return (1);
	}
	else if (ft_strncmp(list[0].cmd, "exit", 4) == 0)
	{
		ftexit(list);
	}
	return (0);
}
