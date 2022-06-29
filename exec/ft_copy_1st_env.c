/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_1st_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:44:48 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/29 11:00:28 by atabiti          ###   ########.fr       */
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
		value[i] = ft_substr(env[i], x, ft_strlen(env[i]) - x);
		x = 0 ;
		// printf(" name %s  \n", name[i]);
		// printf(" value %s  \n", value[i]);
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
	while(x < envp->envpitems)
	{
		printf(" name %s  \n", envp->name[x]);
		printf(" value %s  \n", envp->value[x]);
		x++;
	}
	// new = malloc(sizeof(char **) * (len + 1));

	// while (x < len)
	// {
	// 	if(ft_strncmp(env[x], "SHLVL", 5) == 0)
	// 	{
	// 		char **split = ft_split(env[x], '=');
	// 		int nb = ft_atoi(split[1]);
	// 		nbb = ft_itoa(nb + 1);
	// 		char *joined = ft_strjoin("SHLVL=",  nbb );
	// 		new[x] = joined;
	// 		x++;
	// 	}
	// 	new[x] = env[x];

	// 	x++;
	// }
	// 	// new[x + 1] = "SHLVL=1";
	// envp->environment = new;
	// free(nbb);
}