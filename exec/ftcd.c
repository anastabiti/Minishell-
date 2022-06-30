/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:37:52 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/28 09:14:55 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_home_inenv(t_cmdl *cmd, char *findhome, char *error)
{
	int	len;

	len = 0;
	if (findhome == NULL)
	{
		g_exit_status = 1;
		error = "Minishell: cd: HOME not set\n";
		len = ft_strlen(error);
		write(2, error, len);
		return (1);
	}
	return (0);
}

int	cd_last_check(t_cmdl *cmd, char *error)
{
	int	len;

	len = 0;
	if (chdir(cmd[0].args[0]) == -1)
	{
		g_exit_status = 1;
		error = "Minishell: cd: No such file or directory\n";
		len = ft_strlen(error);
		write(2, error, len);
		return (1);
	}
	return (0);
}

int	ftcd(t_cmdl *cmd, struct s_envp *envp)
{
	int	x;

	x = 0;
	while (x < envp->envpitems)
	{
		cmd->findhome = NULL;
		if (ft_strnstr(envp->environment[x], "HOME=", 5))
		{
			cmd->findhome = envp->environment[x];
			break ;
			// 	return (0);
		}
		x++;
	}
	if (cmd[cmd->cmd_iteration].args[0] == NULL)
	{
		if (check_home_inenv(cmd, cmd->findhome, cmd->error) == 1)
			return (1);
	}
	if (cmd[cmd->cmd_iteration].args[0] == NULL)
	{
		cmd->split = ft_split(cmd->findhome, '=');
		chdir(cmd->split[1]);
		return (0);
	}
	if (cmd[cmd->cmd_iteration].args[1] == NULL)
	{

	
		if(	cd_last_check(cmd, cmd->error) == 1)
		return 1;
	}
	return (0);
}
