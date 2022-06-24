/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asus <asus@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:06:50 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/24 20:56:07 by asus             ###   ########.fr       */
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

int	ft_echo(t_cmdl *list, char *arg, int fd)
{
	int	len;

	if (list[0].args == NULL)
	{
		write(fd, "\n", 1);
		return (0);
	}
	else
	{
		// if (ft_strncmp(list->cmd[1], "$?", 2) == 0)
		// {
		// 	printf("%d\n", g_exit_status);
		// 	return (0);
		// }
		len = ft_strlen(arg);
		write(fd, arg, len);
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

	if (ft_strncmp(cmd[0].cmd ,"echo", 4) == 0)
	{
		ft_echo(cmd, cmd[0].args, cmd->fd_out);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "cd", 2) == 0)
	{
		// findhome = ;
		env = cmd->environ;
		while (*env)
		{
			if (ft_strnstr(*env, "HOME=", 5))
			{
				findhome = *env;
				// printf("%s\n", findhome);
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
		// if (cmd[0]->args[2] != NULL)
		// {
		// 	printf("Minishell: cd: too many arguments\n");
		// }
		if (chdir(cmd[0].args) == -1)
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
	if (ft_strncmp(cmd[0].cmd,"export", 6) == 0)
	{
		ft_export(vr);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "unset", 5) == 0)
	{
		ft_unset(vr);
		return (1);
	}
	return (0);
}

int	ft_is_built_in(t_cmdl *cmd)
{
	int	i;
	int	exit_value;

	i = 0;
	if (builtcheck(cmd) == 1)
	{
		return (1);
	}
	else if (builtcheck_1(cmd) == 1)
	{
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "env", 3) == 0)
	{
		ft_env(cmd->environ, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "pwd", 3) == 0)
	{
		ft_pwd(cmd->fd_out);
		return (1);
	}
	else if (ft_strncmp(cmd[0].cmd, "exit", 4) == 0)
	{
		if (cmd[0].args == NULL)
		{
			printf("exit\n");
			exit(g_exit_status);
		}
		// if (cmd->args[1] == NULL)
		// {
		// 	while (cmd[cmd->cmd_iteration].cmd[1][i])
		// 	{
		// 		if (ft_isdigit(cmd[cmd->cmd_iteration].cmd[1][i]) == 0)
		// 		{
		// 			printf("exit\n");
		// 			printf("Minishell: exit: %s: numeric argument required\n",
		// 					cmd[cmd->cmd_iteration].cmd[1]);
		// 			exit(2); // 				exit(255);
		// 		}
		// 		exit_value = ft_atoi(cmd[cmd->cmd_iteration].cmd[1]);
		// 		i++;
		// 		free(cmd->input);
		// 		exit(exit_value);
		// 	}
		// }
		// printf("exit\n Minishell : exit : too many arguments\n");
		exit(1);
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
