/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_1st_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:44:48 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/29 12:04:08 by atabiti          ###   ########.fr       */
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

	name = malloc(sizeof(char **) * envp->envpitems );
	value = malloc(sizeof(char **) * envp->envpitems );
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
		x = 0 ;
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

	// while(x < envp->envpitems)
	// {
	// // 	printf(" name %s  \n", envp->name[x]);
	// // 	printf(" value %s  \n", envp->value[x]);
	// 	x++;
	// }
		ft_split_env(envp, env);
		new = malloc(sizeof(char **) * (len + 1));

		x  = 0 ;
	while (x < len)
	{  int nb = 0;
		if(ft_strncmp(envp->name[x], "SHLVL", 5) == 0)
		{
								printf("%s" , envp->value[x]);

			// // char **split = ft_split(envp->name[x], '=');
			// printf("%s" , envp->value[x]);
			// nb = ft_atoi(envp->value[x]);
			// printf( "nb is  %d \n\n\n\n\n\n", nb);
			// nbb = ft_itoa(nb + 1);
			// char *joined = ft_strjoin("SHLVL=",  nbb );
			// new[x] = joined;
			// x++;
		}

		new[x] = env[x];
	
		x++;
	}
		// new[x + 1] = "SHLVL=1";
	envp->environment = new;

	// return envp;
	// free(nbb);
}