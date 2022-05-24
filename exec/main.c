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
		blt.cd_path = "/Users/atabiti/Desktop/";
		// char **vr = env;
		add_history(input); // to save commandes history >> you can access it by up arrow ^.
		if (ft_is_built_in(blt, input, env) == 0)
		{
			if (ft_strncmp(input, "ls", 2) == 0)
			{
				int pid = fork();
				if (pid == 0)
				{
					char *cmd_args = "-PA";
					char *a[] = {"ls", cmd_args, NULL};
					execve("/bin/ls", a, NULL);
				}
				waitpid(pid, 0, 0);
			}
			else
			{
				char *joinded;
				joinded = ft_strjoin("/bin/", input);
				if (access(joinded, F_OK) == -1)
				{
					printf("MINISHELL: %s: command not found\n", input);
				}
				else
				{

					int idd = fork();
					if (idd == 0)
					{
						execve(joinded, NULL, NULL);
					}
					waitpid(idd, 0, 0);
				}
			}
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
}
