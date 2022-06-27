/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:37:52 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/27 08:44:01 by atabiti          ###   ########.fr       */
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
		return (0);
	}
	return (1);
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
	}
	return (1);
}

int	ftcd(t_cmdl *cmd)
{
	int	x;

	x = 0;
	while (!(ft_strnstr(cmd->environ[x], "HOME=", 5)))
	{
		x++;
		if (cmd->environ[x] == NULL)
			break ;
	}
	cmd->findhome = cmd->environ[x];
	if (cmd[cmd->cmd_iteration].args[0] == NULL)
	{
		if (check_home_inenv(cmd, cmd->findhome, cmd->error) == 0)
			return (0);
	}
	if (cmd[cmd->cmd_iteration].args[0] == NULL)
	{
		cmd->split = ft_split(cmd->findhome, '=');
		chdir(cmd->split[1]);
		printf("done\n");
		return (0);
	}
	if (cmd[cmd->cmd_iteration].args[1] == NULL)
		cd_last_check(cmd, cmd->error);
	return (1);
}
