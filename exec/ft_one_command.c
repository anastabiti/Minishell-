/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:40:08 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/28 06:57:10 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	one_cmd_1(t_cmdl *list, struct s_envp *envp)
{
	int	i;

	i = 0;
	if (fork() == 0)
	{
		// redirections(list);
		// heredoc_without_cmd(list);
		// while (list[0].type[i] != NULL)
		// {
		// 	if (ft_strncmp(list[0].type[i], HEREDOC, 7) == 0)
		// 		dup2(list->fd_in, 0);
		// 	if (ft_strncmp(list[0].type[i], RDOUT, 7) == 0)
		// 		dup2(list->fd_out, 1);
		// 	if (ft_strncmp(list[0].type[i], RDIN, 6) == 0)
		// 		dup2(list->fd_in, 0);
		// 	if (ft_strncmp(list[0].type[i], RDOUT, 7) == 0)
		// 		close(list->fd_out);
		// 	if (ft_strncmp(list[0].type[i], RDIN, 6) == 0)
		// 		close(list->fd_in);
		// 			if (ft_strncmp(list[0].type[i], HEREDOC, 7) == 0)
		// 		close(list->fd_in);
		// 	i++;
		// }
		ft_bin_usr_sbin(list, envp);
	}
	else
	{
		wait(&g_exit_status);
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		i = 0;
		// while (list->args_execve)
		// {
		// 	free(list->args_execve[i]);
		// 	i++;
		// }
	}
	return (0);
}

int	one_cmd(t_cmdl *cmd, struct						s_envp * envp)
{
	int	i;
	int	x;

	//
	if (cmd->cmd_nbr == 0 && is_builtin(cmd, 0) == 0)
	{
		i = 0;
		// redirections(cmd);
		ft_is_built_in(cmd, envp);
		// if (cmd[0].type[i] != NULL)
		// {
		// 	if (ft_strncmp(cmd[0].type[i], RDOUT, 7) == 0)
		// 	{
		// 		close(cmd->fd_out);
		// 	}
		// 	if (ft_strncmp(cmd[0].type[i], RDIN, 6) == 0)
		// 	{
		// 		close(cmd->fd_in);
		// 	}
		// 	if (ft_strncmp(cmd[0].type[i], RDAPPEND, 10) == 0)
		// 	{
		// 		close(cmd->fd_out);
		// 	}
		// }
		return (1);
	}
	else if (cmd->cmd_nbr == 0 && is_builtin(cmd, 0) == 3)
	{
		one_cmd_1(cmd,envp);
		return (1);
	}
	return (0);
}
