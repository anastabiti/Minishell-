/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/22 09:09:15 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_export(char **env)
{
	char	*to_be_exported;
	int		len;
	int		i;

	to_be_exported = "PATH=/Users/atabiti/.brew/bin:/Users/atabiti/goinfre/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Frameworks/Mono.framework/Versions/Current/Commands";
	len = ft_strlen(to_be_exported);
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], to_be_exported, len))
		{
			return (0);
		}
		i++;
	}
	env[i] = to_be_exported;
	env[i + 1] = NULL;
	return (0);
}
