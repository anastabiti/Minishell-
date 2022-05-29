/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:39:49 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/18 10:40:11 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// ping is /sbin/ping

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	// struct s_builtins blt;
	struct s_list *list;
	char *input;
	list = (struct s_list *)malloc(sizeof(struct s_list) * 20);
	list->blt = (struct s_builtins *)malloc(sizeof(struct s_builtins) * 412);
	int fd = 1;
	list->environ = env;
	while (1)
	{

			list->input = ft_read(list->input);
		//
		int there_is_pipe = 1;
		ft_init(list);
		list[0].cmd[0] = "/bin/ls";
		list[0].cmd[1] = "-l";
		list[0].cmd[2] = NULL;
		list[0].next = &list[1];
		list[1].cmd[0] = "/usr/bin/wc";
		list[1].cmd[1] = "-c";
		list[1].cmd[2] = NULL;
		///
		list[1].next = &list[2];

		list[2].cmd[0] = "/bin/echo";
		list[2].cmd[1] = "anas";
		list[2].cmd[2] = NULL;
		list[2].next = &list[3];
		list[3].cmd[0] = "/usr/bin/wc";
		list[3].cmd[1] = NULL;

		// list[3].cmd[2] = NULL;
		// list->args = {"/bin/ls", "ls", NULL};

		list[3].next = NULL;
		there_is_pipe = 1;

		if (there_is_pipe == 0)
		{
			if (ft_is_built_in(list) == 0)
			{
				ft_bin_usr_sbin(list->input);
			}
		}
		else
		{
			int i = 0;
			int fd_in = 0;
			int fd[2];
			while (i < there_is_pipe + 1)
			{
				pipe(fd);
				if (fork() == 0)
				{
					dup2(fd_in, 0);
					if (i < there_is_pipe)
						dup2(fd[1], 1);
					close(fd[0]);
					// if (i == 0)
					// {
					// 	ft_pwd(fd[1]);
					// 	return 0;
					// }
					// if (i > 0)
					execve(list[i].cmd[0], list[i].cmd, NULL);
				}
				else
				{
					wait(NULL);
					close(fd[1]);
					fd_in = fd[0];
					i++;
				}
			}
		}
	}
	free(input);
}
