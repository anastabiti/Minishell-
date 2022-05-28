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
void handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();				//  Tell the update functions that we have moved onto a new (empty) line
		rl_replace_line("", 0); // needs to include the LIB and /include dir to work
		rl_redisplay();					// Change what's displayed on the screen to reflect the current contents of rl_line_buffer.
	}
}
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	struct s_builtins blt;
	struct s_list *list;
	char *input;
	list = (struct s_list *)malloc(sizeof(struct s_list) * 4);
	while (1)
	{

		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		input = readline("[MINISHELl]$ "); // like getnextline : readline will read a line from the terminal and return it,
		// size_t llenght = ft_strlen(input);
		if (!input) // ctrl-D
		{
			rl_clear_history();
			write(2, "exit\n", 5);
			free(input);
			exit(1);
		}
		blt.echo = "echo";
		blt.cd = "cd";
		blt.pwd = "pwd";
		blt.export = "export";
		blt.unset = "unset";
		blt.env = "env";
		blt.exit = "exit";
		blt.cd_path = "..";
		int there_is_pipe = 0;
		add_history(input); // to save commandes history >> you can access it by up arrow ^.

		list[0].cmd[0] = "/bin/ls";
		list[0].cmd[1] = "-l";
		list[0].cmd[2] = NULL;
		list[0].next = &list[1];
		list[1].cmd[0] = "/usr/bin/wc";
		list[1].cmd[1] = "-l";
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
		there_is_pipe = 0;

		if (there_is_pipe == 0)
		{
			if (ft_is_built_in(blt, input, env) == 0)
			{
				ft_bin_usr_sbin(input);
			}
		}
		else
		{
			int i = 0;
			int fd_in = 0;

			// while (i < there_is_pipe)
			// {
			int fd[there_is_pipe * 2];
			while (i < there_is_pipe)
			{
				pipe(fd + i * 2);
				i++;
			}

			while (i < there_is_pipe )
			{
				if (fork() == 0)
				{
					dup2(fd[i + 1], 1);
					if (i < there_is_pipe)
						dup2(fd[i * 2], 0);
					close(fd[i]);
					execve(list[i].cmd[0], list[i].cmd, NULL);
				}
				else
				{
					close(fd[i]);
					wait(NULL);
					i++;
				}
			}
		}
		// pipe(fd);
		// pipe(fd + 2);
		// pipe(fd + 4);
		// 	if (fork() == 0)

		// 	{
		// 		// dup2(fd_in, 0);
		// 		// if (list[i].cmd != NULL)
		// 		dup2(fd[1], 1);

		// 		close(fd[2]);
		// 		close(fd[3]);
		// 		close(fd[0]);
		// 		close(fd[1]);
		// 		close(fd[5]);
		// 		close(fd[4]);
		// 		execve(list[0].cmd[0], list[0].cmd, NULL);
		// 		// execve(", echo, NULL);

		// 		printf("exec failed \n");
		// 	}
		// 	if (fork() == 0)
		// 	{
		// 		dup2(fd[0], 0);
		// 		dup2(fd[3], 1);

		// 		close(fd[2]);
		// 		close(fd[3]);
		// 		close(fd[0]);
		// 		close(fd[5]);
		// 		close(fd[4]);
		// 		close(fd[1]);
		// 		execve(list[1].cmd[0], list[1].cmd, NULL);
		// 		printf("exec failed \n");
		// 	}
		// 	///
		// 	if (fork() == 0)
		// 	{
		// 		dup2(fd[2], 0);
		// 		dup2(fd[5], 1);

		// 		close(fd[2]);
		// 		close(fd[3]);
		// 		close(fd[0]);
		// 		close(fd[5]);
		// 		close(fd[4]);
		// 		close(fd[1]);
		// 		execve(list[2].cmd[0], list[2].cmd, NULL);
		// 		printf("exec failed \n");
		// 	}
		// 	//
		// 	if (fork() == 0)
		// 	{
		// 		dup2(fd[4], 0);

		// 		close(fd[2]);
		// 		close(fd[3]);
		// 		close(fd[0]);
		// 		close(fd[1]);
		// 		close(fd[5]);
		// 		close(fd[4]);
		// 		execve(list[3].cmd[0], list[3].cmd, NULL);
		// 		printf("exec failed \n");
		// 	}

		// 	else
		// 	{
		// 		close(fd[5]);
		// 		close(fd[4]);
		// 		close(fd[2]);
		// 		close(fd[3]);
		// 		close(fd[0]);
		// 		close(fd[1]);
		// 		wait(NULL);
		// 		wait(NULL);
		// 		wait(NULL);
		// 		wait(NULL);
		// 	}
		// 	// close(fd[1]);
		// 	// fd_in = fd[0];
		// 	// i++;
		// 	// printf(" %s\n", cmds[0][1]);
		// }

		// else
		// {
		// 	printf(" minishell: fewf: command not found\n");
		// }
	}
	free(input);

	// else
	// { // open dir >> read its content to find if there is matched command there
	// 	struct dirent *dd;
	// 	int check = 0;
	// 	DIR *dir = opendir("/bin/");
	// 	char *cmd = "sleep"; // example
	// 	while (((dd = readdir(dir)) != NULL))
	// 	{
	// 		if (ft_strnstr(dd->d_name, cmd, 5))
	// 		{
	// 			int pid = fork();
	// 			if (pid == 0)
	// 			{
	// 				char *ea[] = {cmd, "2", NULL};
	// 				// printf(" %s\n", dd->d_name);

	// 				execve("/bin/sleep", ea, NULL);
	// 			}
	// 			waitpid(pid, 0, 0);
	// 		}
	// 	}
	// 	closedir(dir);
	// }
}
