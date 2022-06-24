/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:17:14 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/24 22:20:33 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	run_builtin_1(struct s_list *list)
{
// 	if (ft_strncmp("echo", list[list->cmd_iteration].cmd[0], 4) == 0)
// 	{
// 		execve("builtins_bin/ftecho", list[list->cmd_iteration].cmd,
// 				list->environ);
// 		exit(127);
// 	}
// 	else if (ft_strncmp("cd", list[list->cmd_iteration].cmd[0], 2) == 0)
// 	{
// 		execve("builtins_bin/ftcd", list[list->cmd_iteration].cmd,
// 				list->environ);
// 		exit(31);
// 	}
// 	else if (ft_strncmp("exit", list[list->cmd_iteration].cmd[0], 4) == 0)
// 	{
// 		execve("builtins_bin/ftexit", list[list->cmd_iteration].cmd,
// 				list->environ);
// 		exit(127);
// 	}
// 	else if (ft_strncmp("pwd", list[list->cmd_iteration].cmd[0], 3) == 0)
// 	{
// 		execve("builtins_bin/ftpwd", list[list->cmd_iteration].cmd,
// 				list->environ);
// 		exit(127);
// 	}
	return (0);
}

int	set_rd(struct s_list *list)
{
	int i = 0;
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

int	run_builtin(struct s_list *list)
{
// 	if (run_builtin_1(list) == 0)
// 	{
// 		if (ft_strncmp("env", list[list->cmd_iteration].cmd[0], 3) == 0)
// 		{
// 			execve("builtins_bin/ftenv", list[list->cmd_iteration].cmd,
// 					list->environ);
// 			exit(127);
// 		}
// 		else if (ft_strncmp("unset", list[list->cmd_iteration].cmd[0], 5) == 0)
// 		{
// 			execve("builtins_bin/ftunset", list[list->cmd_iteration].cmd,
// 					list->environ);
// 			exit(127);
// 		}
// 		else if (ft_strncmp("export", list[list->cmd_iteration].cmd[0], 6) == 0)
// 		{
// 			execve("builtins_bin/ftexport", list[list->cmd_iteration].cmd,
// 					list->environ);
// 			exit(127);
// 		}
// 		else
// 			ft_bin_usr_sbin(list);
// 	}
	return (127);
}
