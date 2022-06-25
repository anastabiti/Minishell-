/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/25 18:22:03 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_export(char **env, t_cmdl *cmd)
{
	char	*to_be_exported;
	int		len;
	int		i;

	if(cmd->args[0] == NULL)
	{
		char	**var;

	var = env;
	while (*var != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(*var, 1);

		var++;
	}
	return 0;
	}
	to_be_exported = "tt=/Users/atabiti/.brew/bin:/Users/atabiti/goinfre/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Frameworks/Mono.framework/Versions/Current/Commands";
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
