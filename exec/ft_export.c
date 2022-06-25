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

int	ft_export_1(char **env, t_cmdl *cmd, char **var)
{
	int		i;
	char	**new;

	if (cmd->args[0] == NULL)
	{
		var = env;
		i = 0;
		while (*var != NULL)
		{
			new = ft_split(*var, '=');
			while (new[i])
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd(new[i], 1);
				write(1, "=\"", 2);
				while (new[i + 1] != NULL)
				{
					ft_putstr_fd(new[i + 1], 1);
					i++;
				}
				write(1, "\"\n", 2);
				i++;
			}
			var++;
			i = 0;
		}
		return (0);
	}
	return (1);
}

int	ft_export(char **env, t_cmdl *cmd)
{
	char	*to_be_exported;
	int		len;
	int		i;
	char	**var;

	if (ft_export_1(env, cmd, var) == 0)
	{
		return (0);
	}
	i = 0;
	int x = 0;
	while (cmd[cmd->cmd_iteration].args[i])
	{
		to_be_exported = cmd[0].args[i];
		len = ft_strlen(to_be_exported);
		while (env[x])
		{
			if (ft_strnstr(env[x], to_be_exported, len))
			{
				break;
			}
			x++;
		}
		env[x] = to_be_exported;
					env[x + 1] = NULL;

		i++;
	}

	return (0);
}
