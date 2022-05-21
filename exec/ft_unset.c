/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:57 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/21 11:25:50 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_unset(char **env)
{
	int x = 0;
	char *to_be_unset;

	int i = 0;
	to_be_unset = "VAR=EXPORETED"; // mkrim must provide me with the string  to  unset
	int lenght = ft_strlen(to_be_unset);
	while (!(ft_strnstr(env[x], to_be_unset, lenght))) // change it later
	{
		x++;
		if (env[x] == NULL)
			return 0;
	}
	while (env[i]) // N of env strings
	{
		i++;
	}
	while (x < i) // copy back backward when one is unset
	{
		env[x] = env[x + 1];
		x++;
	}
	env[i - 1] = NULL;
	return 0;
}