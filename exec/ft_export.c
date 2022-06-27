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

int	ft_export_1(struct						s_envp * envp, t_cmdl *cmd)
{
	int		i;
	char	**new;

	if (cmd->args[0] == NULL)
	{
		i = 0;
		while (*envp->environment != NULL)
		{
			new = ft_split(*envp->environment, '=');
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
			envp->environment++;
			i = 0;
		}
		return (0);
	}
	return (1);
}

int	ft_export(struct						s_envp * envp, t_cmdl *cmd)
{
	char	*to_be_exported;
	int		len;
	int		i;
	char	**var;
	int		x;
	int		t;
	char	**new;
printf("   %d    items n enpv\n", envp->envpitems);
	if (ft_export_1(envp, cmd) == 0)
	{
		return (0);
	}
	i = 0;
	while (cmd[cmd->cmd_iteration].args[i])
	{
		to_be_exported = cmd[0].args[i];
		len = ft_strlen(to_be_exported);
		x = 0;

		while (x < envp->envpitems)
		{
			if (ft_strnstr(envp->environment[x], to_be_exported, len))
			{
				return (0);
			}
			x++;
		}
		// 	increment++;
		// 	cmd->envlen = increment;
		new = malloc(sizeof(char **) * ( envp->envpitems + 1));
		t = 0;
		printf("%d LEN\n\n\n", x);
		while (t <  envp->envpitems)
		{
			new[t] = envp->environment[t];
						// printf("%s old \n", new[t]);

			t++;
		}
		x = x + 1;
		new[t] = to_be_exported;
		// new[t + 1] = NULL;
		t = 0;
		while (t < 	 envp->envpitems)
		{
			printf("%s new\n", new[t]);
			t++;
		}
		// free(envp->environment);
				 envp->envpitems++;

 envp->environment =	new;
		i++;
	}
	return 0;
}
