/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_1st_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:44:48 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/30 16:11:13 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	ft_split_env(struct s_envp *envp, char **env)
{
	int		i;
	int		x;
	char	**split;
	char	*join;
	char	**name;
	char	**value;
	int		len;

	name = malloc(sizeof(char **) * envp->envpitems);
	value = malloc(sizeof(char **) * envp->envpitems);
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
void	ft_copy_1st_env(struct s_envp *envp, char **env)
{
	char **new;
	char *nbb;
	int len;

	int x = 0;
	len = 0;
	while (env[len])
	{
		len++;
	}
	envp->envpitems = len;

	ft_split_env(envp, env);
	new = malloc(sizeof(char **) * (len + 1));
	x = 0;
	while (x < envp->envpitems)
	{
		int nb = 0;
		if (ft_strncmp(envp->name[x], "SHLVL", 6) == 0)
		{
			nb = ft_atoi(envp->value[x]);
			nbb = ft_itoa(nb + 1);
			char *joined = ft_strjoin("SHLVL=", nbb);

			new[x] = joined;
									printf(" in pos  = %d nb = %d  and itoa = %s joined = %s \n new value is %s  ", x, nb, nbb, joined,	new[x] );

			// free(nbb);
			// free(joined);
			x++;
		}
		// if (x == envp->envpitems)
		// {
		// 	new[x] = "SHLVL=1";
		// }
		new[x] = env[x];

		x++;
	}

	envp->environment = new;

	// return (envp);
	// free(nbb);
}