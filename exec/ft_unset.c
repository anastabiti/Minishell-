/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:57 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/29 06:48:45 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
int	ft_search_for_variable_in_env(struct s_envp *envp, t_cmdl *list, int arg)
{
	int	lenght;
	int	x;
	int	i;

	lenght = ft_strlen(list[list->cmd_iteration].args[0]);
	x = 0;
	i = 0;
	while (x < envp->envpitems)
	{
		// list->envsplited = ft_split(envp->environment[x], '=');
		if (ft_strncmp(envp->name[x], list[list->cmd_iteration].args[0], lenght) == 0)
		{
			list->envvarpos = x;
			return (1);
		}
		x++;
	}
	return (0);
}
int	ft_unset(struct s_envp *envp, t_cmdl *list, int arg)
{
	int x = 0;
	char *to_be_unset;
	char **new;
	list->envvarpos = -1;
	int i = 0;
	new = malloc(sizeof(char **) * envp->envpitems - 1);
	int lenght = ft_strlen(list[list->cmd_iteration].args[arg]);
	x = 0;
	int next = 0;

	if (ft_search_for_variable_in_env(envp, list, arg) == 1)
	{
		printf("found  in pos %d \n", list->envvarpos);
		envp->envpitems--;
		while (x < envp->envpitems)
		{
			if (x < list->envvarpos)
				new[x] = envp->environment[x];
			if (x >= list->envvarpos)
				new[x] = envp->environment[x + 1];
			x++;
		}
		envp->environment = new;
		return (0);
	}
	else
		free(new);

	return (0);
}