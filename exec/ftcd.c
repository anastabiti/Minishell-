/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:37:52 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/27 08:27:36 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	char	**env;
	char	*findhome;
	char	*error;
	int		len;
	char	**split;
	int		x;

	env = cmd->environ;
	x = 0;
	while (!(ft_strnstr(env[x], "HOME=", 5)))
	{
		x++;
		if (env[x] == NULL)
		{
			// printf("Minishell: cd: HOME not set\n");
		break;		}
	}
	findhome = env[x];
	if(check_home_inenv(cmd, findhome, error) == 0)
	
	return 0;
	if (cmd[cmd->cmd_iteration].args[0] == NULL)
	{
		split = ft_split(findhome, '=');
		chdir(split[1]);
		printf("done\n");
		return (0);
	}
	cd_last_check(cmd, error);
	return (1);
}
