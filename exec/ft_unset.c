/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:57 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/28 07:22:36 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(struct s_envp *envp, t_cmdl *list, int arg)
{
	int x = 0;
	char *to_be_unset;
	char **new;

	int i = 0;
	to_be_unset = list[list->cmd_iteration].args[arg];
	int lenght = ft_strlen(to_be_unset);
	new = malloc(sizeof(char **) * envp->envpitems - 1);
	// char **split = ft_split(to_be_unset,);
	while (x < envp->envpitems)
	{
		list->envsplited = ft_split(envp->environment[x], '=');
		// while (list->envsplited[i])
		// {	
				printf(" splited %s \n", list->envsplited[i]);

		// }
		// i = 0;
		x++;
	}
	// x = 0;
	// 	int next = 0;
	// 	while (x < envp->envpitems)
	// 	{
	// 		if (ft_strncmp(list->envsplited[next],	to_be_unset, lenght))
	// 		{
	// 			envp->envpitems--;
	// 			while (x < envp->envpitems)
	// 			{
	// 				new[x] = envp->environment[x + 1];
	// 				x++;
	// 			}
	// 			envp->environment = new;
	// 			return (0);
	// 		}
	// 		else
	// 			new[x] = envp->environment[x];

	// 		if (x == envp->envpitems)
	// 			return (0);
	// 		x++;
	// 		next += 2;
	// 	}
	return (0);
}