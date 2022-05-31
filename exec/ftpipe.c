/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/31 09:08:29 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_pipe(struct s_list *list)

{

	if (list->there_is_pipe > 0)
	{
		//
		char *bin;
		char *userbin;
		char *sbin;
		sbin = ft_strjoin("/sbin/", list->input);
		bin = ft_strjoin("/bin/", list->input);
		userbin = ft_strjoin("/usr/bin/", list->input);
		char path[PATH_MAX];
		char *main_path;
		char *pwd = ft_strjoin(getcwd(path, PATH_MAX), "/");
		main_path = ft_strjoin(pwd, list->input);

		//
		int i = 0;
		int fd_in = 0;
		int fd[2];
		while (i < list->there_is_pipe + 1)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd_in, 0);
				if (i < list->there_is_pipe)
					dup2(fd[1], 1);
				close(fd[0]);
				// if (i == 0)
				// {
				// 	if(strncmp(list->input, "echo");)
				// 	ft_pwd(fd[1]);
				// 	return 0;
				// }
				// if (i > 0)
				// if (i == 0)

				// {

				// 	if (access(list->input, F_OK) == 0)
				// 	{
				// 		char *cmd[] = {list->input, NULL};

				// 		execve(list->input, cmd, NULL);
				// 	}

				// 	else if (access(bin, F_OK) == 0)
				// 	{
				// 		char *cmd[] = {list->input, NULL};

				// 		execve(bin, cmd, NULL);
				// 	}
				// 	else if (access(userbin, F_OK) == 0)
				// 	{
				// 		char *cmd[] = {list->input, NULL};

				// 		execve(userbin, cmd, NULL);
				// 	}

				// 	else if (access(main_path, F_OK) == 0)
				// 	{
				// 		char *cmd[] = {list->input, NULL};

				// 		execve(main_path, cmd, NULL);
				// 	}
				// 	else if (access(sbin, F_OK) == 0)
				// 	{
				// 		execve(sbin, NULL, NULL);
				// 	}
				// 	exit(1);
				// }
				
					if (execve(list[i].cmd[0], list[i].cmd, NULL) == -1)
					{
						printf("failed\n");
						return 0;
					}
				}
		
			else
			{
				wait(NULL);
				// list->fd_out = fd[1];
				close(fd[1]);
				fd_in = fd[0];

				i++;
			}
		}
	}
	return 0;
}