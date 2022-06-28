/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/27 12:08:27 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_export_1(struct s_envp *envp, t_cmdl *cmd)
{
	int		i;
	char	**new;
	int		x;

	x = 0;
	if (cmd->args[0] == NULL)
	{
		i = 0;
		while (x < envp->envpitems)
		{
			new = ft_split(envp->environment[x], '=');
			while (new[i])
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd(new[i], 1);
				write(1, "=\"", 2);
				while (new[i + 1] != NULL)
				{
					ft_putstr_fd(new[i + 1], 1);
					i++;
				}
				write(1, "\"\n", 2);
				i++;
			}
			x++;
			i = 0;
		}
		return (0);
	}
	return (1);
}

int	ft_export(struct s_envp *envp, t_cmdl *cmd, int i)
{
	char	*to_be_exported;
	int		len;
	char	**var;
	int		x;
	int		t;
	char	**new;
	char	**split;

	split = ft_split(cmd[0].args[i], '=');
	to_be_exported = split[0];
	
		if (ft_is_alpha(split[0][0]) == 0)
		{
			printf("Minishell: export: `%s': not a valid identifier\n",cmd[0].args[i]);
			return (1);
		}
	
	x = 0;
	// printf("to_be_exported is %s  \n", split[0]);
	len = ft_strlen(split[0]);
	x = 0;
	while (x < envp->envpitems)
	{
		if (ft_strnstr(envp->environment[x], to_be_exported, len))
		{
			envp->environment[x] = cmd[0].args[i];
			return (0);
		}
		x++;
	}
	// printf("DO NOT \n\n\n");
	new = malloc(sizeof(char **) * (envp->envpitems + 1));
	t = 0;
	while (t < envp->envpitems)
	{
		new[t] = envp->environment[t];
		t++;
	}
	x = x + 1;
	new[t] = cmd[0].args[i];
	// new[t + 1] = NULL;
	// t = 0;
	// while (t < envp->envpitems)
	// {
	// 	printf("%s new\n", new[t]);
	// 	t++;
	// }
	// printf("%d LEN\n\n\n", envp->envpitems);
	envp->envpitems++;
	// free(envp->environment);
	envp->environment = new;
	return (0);
}
