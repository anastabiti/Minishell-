/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:06:50 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 11:32:53 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// else if (ft_strncmp(list->input, "$?", 2) == 0)
// {
// 	printf("%d\n", g_status);
// 	return (1);
// }

// if(you pass -n you must remove newline )
// ft_putendl_fd(arg, fd);
// printf("Minishell: cd: %s: No such file or directory\n", list->blt->cd_path);
// // mkrim will provide me with FULL path to CD
// prints out the names and values of the variables in the environment,
// ft_putendl_fd(pw, fd_out);

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
	char	*error;
	int		len;
	char	*findhome;
	char	**env;

	if (ft_strncmp(cmd[0].cmd, "echo", 4) == 0)
	{
		ft_echo(cmd, cmd->fd_out);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "cd", 2) == 0)
	{
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
	return (0);
}

int	builtcheck_1(t_cmdl *cmd)
{
	char	**vr;

	vr = cmd->environ;
	if (ft_strncmp(cmd[0].cmd, "export", 6) == 0)
	{
		ft_export(vr, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "unset", 5) == 0)
	{
		ft_unset(vr);
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
