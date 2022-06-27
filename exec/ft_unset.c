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

int ft_unset(struct						s_envp * envp)
{
	int x = 0;
	char *to_be_unset;

	int i = 0;
	// to_be_unset = "VAR=EXPORETED"; // mkrim must provide me with the string  to  unset
	to_be_unset = "HOME="; // mkrim must provide me with the string  to  unset

	int lenght = ft_strlen(to_be_unset);
	while (!(ft_strnstr(envp->environment[x], to_be_unset, lenght)))
	{
		x++;
		if (envp->environment[x] == NULL)
			return 0;
	}
	while (envp->environment[i]) // N of env strings
	{
		i++;
	}
	while (x < i) // copy back backward when one is unset
	{
		envp->environment[x] = envp->environment[x + 1];
		x++;
	}
	envp->environment[i - 1] = NULL;
	return 0;
}