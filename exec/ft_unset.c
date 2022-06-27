/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:57 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 11:48:06 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_unset(struct						s_envp * envp, t_cmdl *list)
{
	int x = 0;
	char *to_be_unset;
	char **new;

	int i = 0;
	// to_be_unset = "VAR=EXPORETED"; // mkrim must provide me with the string  to  unset
	to_be_unset =list[list->cmd_iteration].args[0]; // mkrim must provide me with the string  to  unset

	int lenght = ft_strlen(to_be_unset);
			new = malloc(sizeof(char **) * envp->envpitems);

	while (!(ft_strnstr(envp->environment[x], to_be_unset, lenght)))
	{
		x++;
		new[x] = envp->environment[x]; // must free 
		printf("%s \n", new[x]);

		if (envp->environment[x] == NULL)
			return 0;
	}
	printf("   %d \n", x);
	// while (envp->environment[i]) // N of env strings
	// {
	// 	i++;
	// }
	envp->envpitems--;
	while (x < envp->envpitems) // copy back backward when one is unset
	{
		new[x] = envp->environment[x + 1];
		printf("%s \n", new[x]);
		x++;
	}
	// envp->environment[i - 1] = NULL;
	envp->environment = new;
	return 0;
}