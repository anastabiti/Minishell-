/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:41:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/30 18:39:50 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	free2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}
int	check_exit_no_args(t_cmdl *cmd, struct s_envp *envp)
{
	if (cmd[cmd->cmd_iteration].args[0] == NULL)
	{
		printf("exit\n");
		rl_clear_history();
		free2d(envp->name);
		free2d(envp->value);
		exit(g_exit_status);
	}
	return (0);
}

int	check_exit_with_args(t_cmdl *cmd, struct s_envp *envp)
{
	int	i;
	int	exit_value;

	i = 0;
	if (cmd->args[1] == NULL)
	{
		i = 0;
		while (cmd[cmd->cmd_iteration].args[0])
		{
			while (cmd[cmd->cmd_iteration].args[0][i])
			{
				if (!(ft_isdigit(cmd[cmd->cmd_iteration].args[0][i])))
				{
					printf("exit\n");
					printf("Minishell: exit: %s: numeric argument required\n",
							cmd[cmd->cmd_iteration].cmd);
					free2d(envp->name);
					free2d(envp->value);
					exit(255);
				}
				i++;
			}
			exit_value = ft_atoi(cmd[cmd->cmd_iteration].args[0]);
			free2d(envp->name);
			free2d(envp->value);
			exit(exit_value);
		}
	}
	return (0);
}

int	ftexit(t_cmdl *cmd, struct s_envp *envp)
{
	check_exit_no_args(cmd, envp);
	check_exit_with_args(cmd, envp);
	printf("exit\n Minishell : exit : too many arguments\n");
	free2d(envp->name);
	free2d(envp->value);
	// g_exit_status =2 ;
	exit(2);
}