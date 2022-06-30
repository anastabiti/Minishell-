/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/30 14:26:50 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	modify_name(struct s_envp *envp, t_cmdl *cmd, char **split, int i)
{
	int	x;

	x = 0;
	while (x < envp->envpitems)
	{
		if (ft_strncmp(envp->name[x], split[0], ft_strlen(split[0]) + 1) == 0)
		{
			if (split[1])
				envp->environment[x] = cmd[0].args[i];
			return (0);
		}
		x++;
	}
	return (1);
}

int	ft_export(struct s_envp *envp, t_cmdl *cmd, int i)
{
	char	**var;
	int		x;
	int		t;
	char	**new;
	char	**split;

	split = ft_split(cmd[0].args[i], '=');
	if (check_name_is_valid(split, i, cmd) == 1)
		return (1);
	if (modify_name(envp, cmd, split, i) == 0)
		return (0);
	new = malloc(sizeof(char **) * (envp->envpitems + 1));
	t = 0;
	while (t < envp->envpitems)
	{
		new[t] = envp->environment[t];
		t++;
	}
	x = x + 1;
	new[t] = cmd[0].args[i];
	envp->envpitems++;
	envp->environment = new;
	ft_split_env(envp, envp->environment);
	return (0);
}
