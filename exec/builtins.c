/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:06:50 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/28 10:58:20 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(t_cmdl *list, int fd)
{
	int	len;
	len  = 0;
	if (list[0].args[0] == NULL)
	{
		write(fd, "\n", 1);
		return (0);
	}
	else
	{
		if (ft_strncmp(list[list->cmd_iteration].args[0], "$?", 3) == 0)
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

int	builtcheck(t_cmdl *cmd, struct s_envp *envp)
{
	if (ft_strncmp(cmd[0].cmd, "echo", 5) == 0)
	{
		ft_echo(cmd, cmd->fd_out);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "cd", 3) == 0)
	{
		ftcd(cmd, envp);
		return (1);
	}
	return (0);
}

int	builtcheck_1(t_cmdl *cmd, struct s_envp *envp)
{
	int	i;

	i = 0;
	if (ft_strncmp(cmd[0].cmd, "export", 7) == 0)
	{
		if (cmd->args[0] == NULL)
		{
			if (ft_export_1(envp, cmd) == 0)
				return (0);
		}
		while (cmd[cmd->cmd_iteration].args[i])
		{
			ft_export(envp, cmd, i);
			i++;
		}
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "unset", 6) == 0)
	{
		i = 0;
		if (cmd[cmd->cmd_iteration].args[i] == NULL)
		{
			return (0);
		}
		while (cmd[cmd->cmd_iteration].args[i])
		{
			ft_unset(envp, cmd, i);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_pwd(int fd_out)
{
	char	pw[PATH_MAX];
	char	*pwd;
	int		len;

	fd_out = 1;
	len = 0;
	pwd = getcwd(pw, PATH_MAX);
	len = ft_strlen(pwd);
	write(fd_out, pwd, len);
	write(fd_out, "\n", 1);
	return (1);
}
