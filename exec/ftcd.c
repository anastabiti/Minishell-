/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:37:52 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 11:55:23 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ftcd(t_cmdl *cmd)
{
	char	**env;
	char	*findhome;
	char	*error;
	int		len;

	env = cmd->environ;
	while (*env)
	{
		if (ft_strnstr(*env, "HOME=", 5))
		{
			findhome = *env;
		}
		env++;
	}
	if (findhome == NULL)
	{
		g_exit_status = 1;
		error = "Minishell: cd: HOME not set\n";
		len = ft_strlen(error);
		write(2, error, len);
        exit(1);
	}
    if(cmd[cmd->cmd_iteration].args[0]  == NULL)
    {
        char **split = ft_split(findhome, '=');
        chdir(split[1]);
        printf("done\n");
        return (0);
    }
	if (chdir(cmd[0].args[0]) == -1)
	{
		g_exit_status = 1;
		error = "Minishell: cd: No such file or directory\n";
		len = ft_strlen(error);
		write(2, error, len);
	}
	return (1);
}
