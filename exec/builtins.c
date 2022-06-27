/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:06:50 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/27 10:36:34 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(t_cmdl *list, int fd)
{
	int	len;

	if (list[0].args[0] == NULL)
	{
		write(fd, "\n", 1);
		return (0);
	}
	else
	{
		if (ft_strncmp(list[list->cmd_iteration].args[0], "$?", 2) == 0)
		{
			printf("%d\n", g_exit_status);
			return (0);
		}
		len = ft_strlen(list->args[0]);
		write(fd, list->args[0], len);
		write(fd, "\n", 1);
	}
	return (0);
}

int	builtcheck(t_cmdl *cmd)
{
	if (ft_strncmp(cmd[0].cmd, "echo", 4) == 0)
	{
		ft_echo(cmd, cmd->fd_out);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "cd", 2) == 0)
	{
		ftcd(cmd);
		return (1);
	}
	return (0);
}

int	builtcheck_1(t_cmdl *cmd, struct s_envp *envp, t_cmdl *list)
{
	int	i;

	if (ft_strncmp(cmd[0].cmd, "export", 6) == 0)
	{
		i = 0;
		if (cmd->args[0] == NULL)
	{
		if(ft_export_1(envp, cmd) == 0)
		return 0;
	}
		while (list[cmd->cmd_iteration].args[i])
		{
			ft_export(envp, cmd);
			i++;
		}
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "unset", 5) == 0)
	{
		ft_unset(envp, list);
		return (1);
	}
	return (0);
}

int	ft_pwd(int fd_out)
{
	char	pw[PATH_MAX];
	char	*pwd;
	int		len;

	pwd = getcwd(pw, PATH_MAX);
	len = ft_strlen(pwd);
	write(fd_out, pwd, len);
	write(fd_out, "\n", 1);
	return (1);
}
