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
int	ft_sort_env(struct s_envp *envp, t_cmdl *cmd)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;
	char	*tmp1;
	char	**joined;

	joined = malloc(sizeof(char **) * 101);
	i = 0;
	j = 0;
	while (i < envp->envpitems)
	{
		tmp1 = ft_strjoin(envp->name[i], "=\"");
		joined[i] = ft_strjoin(tmp1, envp->value[i]);
		i++;
	}
	i = 0;
	while (i < envp->envpitems)
	{
		j = i + 1;
		while (j < envp->envpitems)
		{
			// tmp = malloc(sizeof(char *) * ft_strlen(joined[i]));
			if (strcmp(envp->name[i], envp->name[j]) > 0)
			{
				tmp = joined[i];
				joined[i] = joined[j];
				joined[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < envp->envpitems)
	{
		printf("declare -x %s\"\n", joined[i]);
		i++;
	}
	i = 0;
	while (i < envp->envpitems)
	{
		free(joined[i]);
		i++;
	}
	free(joined);
	return (0);
}
int	ft_export_1(struct s_envp *envp, t_cmdl *cmd)
{
	int		i;
	char	**new;
	char	*clone;
	int		x;

	x = 0;
	if (cmd->args[0] == NULL)
	{
		i = 0;
		ft_sort_env(envp, cmd);
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
		printf("Minishell: export: `%s': not a valid identifier\n",
				cmd[0].args[i]);
		return (1);
	}
	x = 0;
	printf("to_be_exported is %s  \n", split[0]);
	len = ft_strlen(split[0]);
	x = 0;
	while (x < envp->envpitems)
	{
		if (ft_strncmp(envp->name[x], to_be_exported, len) == 0)
		{
			if (split[1])
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
	ft_split_env(envp, envp->environment);
	return (0);
}
