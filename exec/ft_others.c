/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:24:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 10:02:43 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_args_len(t_cmdl *list)
{
	int	len;

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

	len = cmd_args_len(list);
	list->args_execve = malloc(sizeof(char **) * len);
	i = 0;
	while (i < len)
	{
		list->args_execve[0] = list[list->cmd_iteration].cmd;
		list->args_execve[i + 1] = list[list->cmd_iteration].args[i];
		i++;
	}
	list->args_execve[i] = NULL;
	return (list->args_execve);
}

int	ft_check_programs(t_cmdl *list)
{
	char	**argv;
	int		x;

	if (list[list->cmd_iteration].cmd[0] == '.'
		&& list[list->cmd_iteration].cmd[1] == '/')
	{
		argv = create_argv_for_execve(list);
		execve(list[list->cmd_iteration].cmd, argv, NULL);
		printf("Minishell : %s : No such file or directory\n",
			list[list->cmd_iteration].cmd);
		exit(127);
	}
	if (list[list->cmd_iteration].cmd[0] == '/')
	{
		argv = create_argv_for_execve(list);
		execve(list[list->cmd_iteration].cmd, argv, NULL);
		printf("Minishell : %s : No such file or directory\n",
			list[list->cmd_iteration].cmd);
		exit(127);
	}
	return (0);
}

int	ft_bin_usr_sbin(t_cmdl *list)
{
	char	*bin;
	int		i;
	char	*last;

	ft_check_programs(list);
	ftcheck_nopath(list);
	i = 0;
	bin = ft_strjoin(list->new[i], "/");
	looping_through_split_path(list, i, bin, last);
	write(2, "MINISHELL command not found\n", 28);
	exit(127);
}
