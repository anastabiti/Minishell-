/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_1st_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:44:48 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/29 10:15:35 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"
//name=value
int	ft_split_env(struct s_envp *envp, char **env)
{
	int		i;
	int		x;
	char	**split;
	char	*join;
	char	**name;
	char	**value;

	name = malloc(sizeof(char **) * envp->envpitems);
	value = malloc(sizeof(char **) * envp->envpitems);
	i = 0;
	x = 0;
	while (i < envp->envpitems)
	{
		split = ft_split(env[i], '=');
		while (split[x])
		{
			name[i] = split[x];
			while(split[x + 1]  != NULL)
			{
							value[i] = split[x + 1];
					x++;
			}
		
			x ++;
		}
			printf("name  %s 	\n", name[i]);
			printf("value  %s 	\n", value[i]);
		x = 0;
		i++;
	}
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