/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_1st_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:44:48 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/01 10:30:00 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	ft_split_env(struct s_envp *envp, char **env)
{
	int		i;
	int		x;
	char	**name;
	char	**value;
	int		len;

	name = malloc(sizeof(char **) * envp->envpitems + 1);
	value = malloc(sizeof(char **) * envp->envpitems + 1);
	i = 0;
	x = 0;
	len = 0;
	while (i < envp->envpitems)
	{
		while (env[i][x] != '=')
		{
			x++;
		}
		name[i] = ft_substr(env[i], len, x);
		value[i] = ft_substr(env[i], x + 1, ft_strlen(env[i]) - x);
		x = 0;
		i++;
	}
	envp->value = value;
	envp->name = name;
	return (0);
}

int	ft_strlenenv(struct s_envp *envp, char **env)
{
	
	ft_split_env(envp, env);
	return (0);
}

int	ft_copy_env(struct s_envp *envp, char **env)
{
	char	*joined;
	char	*nbb;
	int		x;
	int		nb;
	char	**new;

	new = malloc(sizeof(char **) * (envp->envpitems + 1));
	x = 0;
	while (x < envp->envpitems)
	{
		nb = 0;
		if (ft_strncmp(envp->name[x], "SHLVL", 6) == 0)
		{
			nb = ft_atoi(envp->value[x]);
			nbb = ft_itoa(nb + 1);
			joined = ft_strjoin("SHLVL=", nbb);
			new[x] = joined;
			free(nbb);
			x++;
		}
		new[x] = env[x];
		x++;
	}
	envp->environment = new;
	return (0);
}

int	ft_copy_1st_env(struct s_envp *envp, char **env)
{
	int	len;

	len = 0;
	while (env[len])
	{
		len++;
	}
	envp->envpitems = len;
	ft_strlenenv(envp, env);
	ft_copy_env(envp, env);
	return (0);
}
