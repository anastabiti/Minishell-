/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/27 12:08:27 by atabiti          ###   ########.fr       */
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
	int		x;
	int		t;
	char	**new;
	static int increment;
	increment = cmd->envlen;
	if (ft_export_1(cmd->myenvp, cmd, NULL) == 0)
	{
		return (0);
	}
	i = 0;
	while (cmd[cmd->cmd_iteration].args[i])
	{
		to_be_exported = cmd[0].args[i];
		len = ft_strlen(to_be_exported);
		x = 0;
		while (cmd->myenvp[x])
		{
			if (ft_strnstr(cmd->myenvp[x], to_be_exported, len))
			{
				return (0);
			}
			x++;
		}
		increment++;
		cmd->envlen = increment;
		new = malloc(sizeof(char **) * cmd->envlen + 1);
		t = 0;
			printf("%d LEN\n", cmd->envlen);
		while (t < cmd->envlen)
		{
			new[t] = cmd->myenvp[t];
						printf("%s new\n", cmd->myenvp[t]);

			t++;
		}
	
		new[t] = to_be_exported;
		new[t + 1] = NULL;
			free(cmd->myenvp);

		cmd->myenvp = new;

		i++;
	}
	return (0);
}
