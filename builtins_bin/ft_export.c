/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:28:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 13:24:33 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*to_be_exported;
	int		len;
	int		i;

	to_be_exported = av[1];
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
