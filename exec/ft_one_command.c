/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:40:08 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/27 11:48:12 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	one_cmd_1(t_cmdl *list)
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
		ft_bin_usr_sbin(list);
	}
	else
	{
		wait(&g_exit_status);
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		i = 0;
		while (list->args_execve)
		{
			free(list->args_execve[i]);
			i++;
		}
	}
	return (0);
}

int	one_cmd(t_cmdl *cmd)
{
	int	i;
	int x = 0;
	int len = 0 ;
	while(cmd->environ[len])
	{
		len++;
		
	}
	printf("%d\n", len);
	cmd->envlen  = len;
	cmd->myenvp =  malloc(sizeof(char ** ) * cmd->envlen);
	while (x < len)
	{
		cmd->myenvp[x] = cmd->environ[x];
	// printf("%s\n", cmd->myenvp[x]);
		x++;
	}
// cmd->myenvp[x + 1] = NULL;	
	//
	if (cmd->cmd_nbr == 0 && is_builtin(cmd, 0) == 0)
	{
		i = 0;
		// redirections(cmd);
		ft_is_built_in(cmd);
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
		one_cmd_1(cmd);
		return (1);
	}
	return (0);
}
