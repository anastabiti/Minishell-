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
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		char *input = readline("[MINISHELl]$ "); // like getnextline : readline will read a line from the terminal and return it,
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
		if (ft_is_built_in(blt, input, env) == 0)
		{
			ft_bin_usr_sbin(input); // run other commands in /usr/bin/ and in /bin/
			there_is_pipe = 4;

			char *ls[] = {"ls", "-l", NULL};
			char *grep[] = {"grep", "a", NULL};
			char *echo[] = {"echo", "anas ", NULL};
			char *wc[] = {"wc", "-l", NULL};
			char **cmds[] = {ls, grep, echo, wc, NULL};
			int fd[2];
			int i = 0;
			int fd_in = 0;
			while (*cmds != NULL)
			{

				pipe(fd);
				if (fork() == 0)
				{
					dup2(fd_in, 1);

					if (*(cmds + 1) != NULL)

						dup2(fd[1], 1);

					close(fd[0]);
					execve(*cmds[0], cmds[i], NULL);
				}
				else
				{
					wait(NULL);
					close(fd[1]);
					fd_in = fd[0];
					// printf(" %s\n", cmds[0][1]);
					cmds++;
				}
			}

			// if (there_is_pipe >= 1) // if there is a pipe fork and dup2
			// 	{
			// 		int i = 0;
			// 		int fd[2];
			// 		char *cmd[4];
			// 		cmd[0] = "/bin/ls";
			// 		cmd[1] = "-l";
			// 		cmd[2] = "/usr/bin/wc";
			// 		cmd[3] = "-l";

			// 		while (i < there_is_pipe)
			// 		{
			// 			// pipe(fd + i);
			// 			if (fork() == 0)
			// 			{
			// 				// dup2(fd[1], 1);
			// 				execve(cmd[i], &cmd[i + 1], NULL);
			// 			}
			// 			i++;
			// 		}
			// 		int x = 0;
			// 		while (x < 2)
			// 		{
			// 			wait(0);
			// 			x++;
			// 		}
			// 		// int fd[4];
			// 		// pipe(fd);
			// 		// pipe(&fd[2]);
			// 		// // pipe(fd + 2);

			// 		// if (fork() == 0)
			// 		// {
			// 		// 	dup2(fd[1], 1);

			// 		// 	close(fd[0]);
			// 		// 	close(fd[2]);
			// 		// 	close(fd[3]);
			// 		// 	char *cmd[] = {"ls", NULL};
			// 		// 	execve("/bin/ls", cmd, NULL);
			// 		// }
			// 		// if (fork() == 0)
			// 		// {
			// 		// 	dup2(fd[0], 0);
			// 		// 	dup2(fd[3], 1);
			// 		// 	close(fd[1]);
			// 		// 	close(fd[2]);
			// 		// 	char *cmd[] = {"cat", "Makefile", NULL};
			// 		// 	execve("/bin/cat", cmd, NULL);
			// 		// }
			// 		// if (fork() == 0)
			// 		// {
			// 		// 	dup2(fd[2], 0);
			// 		// 	close(fd[0]);
			// 		// 	close(fd[1]);
			// 		// 	close(fd[3]);
			// 		// 	char *cmd[] = {"wc", "-l", NULL};
			// 		// 	execve("/usr/bin/wc", cmd, NULL);
			// 		// }
			// 		// close(fd[0]);
			// 		// close(fd[1]);

			// 		// close(fd[2]);
			// 		// close(fd[3]);
			// 		// wait(0);
			// 		// wait(0);
			// 		// wait(0);
			// 	}
		}
		// else
		// {
		// 	printf(" minishell: fewf: command not found\n");
		// }
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
}
