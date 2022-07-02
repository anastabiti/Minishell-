/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/02 11:51:25 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	modify_name(struct s_envp *envp, t_cmdl *cmd, char **split, int i)
{
	int	x;
	int	t;

	x = 0;
	t = 0;
	x = 0;
	while (x < envp->envpitems)
	{
		if (ft_strncmp(envp->name[x], split[0], ft_strlen(split[0]) + 1) == 0)
		{
			while (cmd[cmd->cmd_iteration].args[i][t])
			{
				if (cmd[cmd->cmd_iteration].args[i][t] == '=')
				{
					envp->environment[x] = cmd[cmd->cmd_iteration].args[i];
					return (0);
				}
				t++;
			}
			t = 0;
		}
		x++;
	}
	return (1);
}

int	ft_export(struct s_envp *envp, t_cmdl *cmd, int i)
{
	char	**var;
	int		t;
	char	**new;
	char	**split;
	int		len;
	int		x;

	len = 0;
	if (cmd[0].args[i][0] == '=')
	{
		printf("Minishell: export: `%s': not a valid identifier\n",
				cmd[cmd->cmd_iteration].args[i]);
		return (1);
	}
	x = 0;
	new = malloc(sizeof(char **) * (envp->envpitems + 2));
	while (cmd[cmd->cmd_iteration].args[i][x])
	{
		if (cmd[cmd->cmd_iteration].args[i][x] == '=')
		{
			split = ft_split(cmd[cmd->cmd_iteration].args[i], '=');
			if (check_name_is_valid(split, i, cmd) == 1)
				return (1);
			if (modify_name(envp, cmd, split, i) == 0)
				return (0);
			t = 0;
			while (t < envp->envpitems)
			{
				new[t] = envp->environment[t];
				t++;
			}
			new[t] = cmd[cmd->cmd_iteration].args[i];
			envp->envpitems++;
			envp->environment = new;
			ft_split_env(envp, envp->environment);
			return (0);
		}
		x++;
	}
	x = 0;
	split = ft_split(cmd[cmd->cmd_iteration].args[i], ' ');
	printf("export %s \n", split[0]);
	if (check_name_is_valid(cmd[cmd->cmd_iteration].args, i, cmd) == 1)
		return (1);
	while (x < envp->envpitems)
	{
		if (ft_strncmp(envp->name[x], split[0], ft_strlen(split[0]) + 1) == 0)
		{
			return (0);
		}
		x++;
	}
	t = 0;
	while (t < envp->envpitems)
	{
		new[t] = envp->environment[t];
		t++;
	}
	new[t] =split[0];
	new[t + 1] = NULL;
	envp->envpitems++;
	envp->environment = new;
	// ft_split_env(envp, envp->environment);
	 ft_copy_1st_env(envp, envp->environment);

	return (0);
}
