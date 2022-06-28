/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:17:14 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/28 10:14:22 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	run_builtin_1(t_cmdl *list, struct s_envp *envp)
{
	char	**argv;

	if (ft_strncmp("echo", list[list->cmd_iteration].cmd, 4) == 0)
	{
		argv = create_argv_for_execve(list);
		execve("builtins_bin/ftecho", argv, envp->environment);
		exit(127);
	}
	else if (ft_strncmp("cd", list[list->cmd_iteration].cmd, 2) == 0)
	{
		argv = create_argv_for_execve(list);
		execve("builtins_bin/ftcd", argv, envp->environment);
		exit(31);
	}
	else if (ft_strncmp("exit", list[list->cmd_iteration].cmd, 4) == 0)
	{
		argv = create_argv_for_execve(list);
		execve("builtins_bin/ftexit", argv, envp->environment);
		exit(127);
	}
	else if (ft_strncmp("pwd", list[list->cmd_iteration].cmd, 3) == 0)
	{
		argv = create_argv_for_execve(list);
		execve("builtins_bin/ftpwd", argv, envp->environment);
		exit(127);
	}
	return (0);
}

int	set_rd(struct s_list *list)
{
	int	i;

	i = 0;
	while (list[list->cmd_iteration].type[i] != NULL)
	{
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDOUT, 7) == 0)
			dup2(list->fd_out, 1);
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDIN, 6) == 0)
			dup2(list->fd_in, 0);
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDAPPEND, 10) == 0)
			dup2(list->fd_out, 1);
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDOUT, 7) == 0)
			close(list->fd_out);
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDIN, 6) == 0)
			close(list->fd_in);
		if (ft_strncmp(list[list->cmd_iteration].type[i], RDAPPEND, 10) == 0)
			close(list->fd_out);
		i++;
	}
	return (0);
}

int	run_builtin(t_cmdl *list, struct s_envp *envp)
{
	char	**argv;
	int		i;

	if (run_builtin_1(list, envp) == 0)
	{
		if (ft_strncmp("env", list[list->cmd_iteration].cmd, 3) == 0)
		{
			// argv = create_argv_for_execve(list);
			// execve("builtins_bin/ftenv", argv, envp->environment);
			ft_env(envp, list);
			exit(127);
		}
		else if (ft_strncmp("unset", list[list->cmd_iteration].cmd, 5) == 0)
		{
			// argv = create_argv_for_execve(list);
			// execve("builtins_bin/ftunset", argv, envp->environment);
			i = 0;
			
			while (list[list->cmd_iteration].args[i])
			{
				ft_unset(envp, list, i);
				i++;
			}
			exit(127);
		}
		else if (ft_strncmp("export", list[list->cmd_iteration].cmd, 6) == 0)
		{
			// argv = create_argv_for_execve(list);
			// execve("builtins_bin/ftexport", argv, envp->environment);
			i = 0;
			while (list[list->cmd_iteration].args[i])
			{
				ft_export(envp, list, i);
				i++;
			}
			exit(127);
		}
		else
			ft_bin_usr_sbin(list, envp);
	}
	exit (127);
}
