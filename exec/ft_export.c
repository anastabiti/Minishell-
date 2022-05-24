/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/21 11:28:45 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_export(char **env)
{
	char *to_be_exported = "VAR=EXPORETED";
	int len;

	len = ft_strlen(to_be_exported);
	int i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], to_be_exported, len))
		{
			return 0;
		}
		i++;
	}
	env[i] = to_be_exported;
	env[i + 1] = NULL;
	return 0;
}