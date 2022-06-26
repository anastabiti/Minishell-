/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:41:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 11:19:59 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_exit_no_args(t_cmdl *cmd)
{
	if (cmd[cmd->cmd_iteration].args[0] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	return (0);
}

int	check_exit_with_args(t_cmdl *cmd)
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
					exit(255);
				}
				i++;
			}
			exit_value = ft_atoi(cmd[cmd->cmd_iteration].args[0]);
			exit(exit_value);
		}
	}
	return (0);
}

int	ftexit(t_cmdl *cmd)
{
	check_exit_no_args(cmd);
	check_exit_with_args(cmd);
	printf("exit\n Minishell : exit : too many arguments\n");
	return (0);
}
