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
int prompt_and_parse(char **upstream, char **downstream) // not mine is from a course i use it to accelerate work
{
	char *line;

	downstream[0] = NULL;
	// printf("> ");
	line = readline("[MINISHELl]$ ");
	if (line == NULL)
	{
		write(2, "exit\n", 5);
		rl_clear_history();

		free(line);
		exit(1);
	}
	add_history(line); // to save commandes history >> you can access it by up arrow ^.

	*upstream++ = strtok(line, " \t");
	while ((*upstream = strtok(NULL, " \t")))
	{
		if (strcmp(*upstream, "|") == 0)
		{
			*upstream = NULL;
			while ((*downstream++ = strtok(NULL, " \t")))
				/* Empty body */;
			return 1;
		}
		upstream++;
	}

	return 1;
}
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	// struct s_builtins blt;
	struct s_list *list;
	char *input;
	list = (struct s_list *)malloc(sizeof(struct s_list) * 4);
	list->blt = (struct s_builtins *)malloc(sizeof(struct s_builtins) * 412);
	int fd = 1;
	list->environ = env;
	//
	char *upstream[20], *downstream[20];
	// while (1)
	// {
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);

	while (prompt_and_parse(upstream, downstream) > 0)
	{

		list->input = ft_read(list->input);
		//

		ft_init(list);
		list[0].cmd[0] = upstream[0];
		// list[0].cmd[0] = "cdfgfd";

		list[0].cmd[1] = upstream[1];

		// list[0].cmd[2] = upstream[2];

		// // list[0].next = &list[1];
		// // list[1].cmd[0] = "/usr/bin/wc";
		// // list[1].cmd[1] = "-l";
		list[0].next = NULL;
		// list[1].cmd[0] = "ls";
		// // list[1].cmd[1] = "ff=ff";

		// list[1].cmd[1] = NULL;

		// ///
		// list[1].next = &list[2];

		// list[2].cmd[0] = "env";
		// list[2].cmd[1] = NULL;
		// list[2].next = &list[3];

		// list[3].cmd[0] = "wc";

		// list[3].cmd[1] = NULL;
		// list[3].next = NULL;
		// list->there_is_pipe = 1;
		// list->cmd_nbr = 2;
		if (downstream[0] == NULL)
		{
			{

				// if (list->there_is_pipe == 0)
				// {
				if (ft_is_built_in(list) == 0)
				{
					if (fork() == 0)
					{
						ft_bin_usr_sbin(list);
					}
					else
					{
						wait(NULL);
						// if (WIFEXITED(g_status))
						// {
						// 	g_status = WEXITSTATUS(g_status);
						// }
					}
				}
				// else
				// {
				// 	g_status = 127;
				// }
			}

			// if (list->there_is_pipe > 0)
			// {

			// 	ft_pipe(list);
			// }
		}
		// free(input);
	}
	return 0;
}
