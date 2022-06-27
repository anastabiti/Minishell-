/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:24:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 11:21:06 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_args_len(t_cmdl *list)
{
	int	len;

	len = 0;
	while (list[list->cmd_iteration].args[len] != NULL)
	{
		len++;
	}
	return (len);
}

char	**create_argv_for_execve(t_cmdl *list)
{
	int	len;
	int	i;

	len = 0;
		i = 0;

	len = cmd_args_len(list);
	if(len == 0)
	{
			list->args_execve = malloc(sizeof(char **) * 1);

				list->args_execve[0] = list[list->cmd_iteration].cmd;

		list->args_execve[1] = NULL;
	return (list->args_execve);
	}
	list->args_execve = malloc(sizeof(char **) * len);
	while (i < len)
	{
		list->args_execve[0] = list[list->cmd_iteration].cmd;
		list->args_execve[i + 1] = list[list->cmd_iteration].args[i];
		i++;
	}
	list->args_execve[i] = NULL;
	return (list->args_execve);
}

int	ft_check_programs(t_cmdl *list, struct s_envp *envp)
{
	char	**argv;

	if (list[list->cmd_iteration].cmd[0] == '.'
		&& list[list->cmd_iteration].cmd[1] == '/')
	{
		argv = create_argv_for_execve(list);
		execve(list[list->cmd_iteration].cmd, argv, envp->environment);
		printf("Minishell : %s : No such file or directory\n",
			list[list->cmd_iteration].cmd);
		exit(127);
	}
	if (list[list->cmd_iteration].cmd[0] == '/')
	{
		argv = create_argv_for_execve(list);
		execve(list[list->cmd_iteration].cmd, argv, envp->environment);
		printf("Minishell : %s : No such file or directory\n",
			list[list->cmd_iteration].cmd);
		exit(127);
	}
	return (0);
}

int	ft_bin_usr_sbin(t_cmdl *list, struct s_envp *envp)
{
	char	*bin;
	int		i;
	char	*last;

	ft_check_programs(list, envp);
	ftcheck_nopath(list, envp);
	i = 0;
	bin = ft_strjoin(list->new[i], "/");
	looping_through_split_path(list, i, bin, last, envp);
	write(2, "MINISHELL command not found\n", 28);
	// g_exit_status = 127;
	exit(127);
}
