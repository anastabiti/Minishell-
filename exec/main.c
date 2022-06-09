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


int	is_builtin(struct s_list *list, int i)
{
	if (list[i].cmd[i] == NULL)
		return (0);
	if (ft_strncmp(list[i].cmd[i] , "cd", 2) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i] , "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i] , "echo", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i] , "env", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i] , "exit", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i] , "unset", 5) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i] , "export", 6) == 0)
		return (0);
	return (3);
}
int prompt_and_parse(char **upstream, char **downstream, char *line) // not mine is from a course i use it to accelerate work
{

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
			while ((*downstream++ = strtok(NULL, " |")))
				/* Empty body */;

			return 1;
		}
		upstream++;
	}
downstream[0] = NULL;
	
	return 1;
}
// ps | pwd | wc
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
	
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);

	while (prompt_and_parse(upstream, downstream, list->input) > 0)
	{

		// list->input = ft_read(list->input);
		//

		ft_init(list);
		list->redir = ">";
		list[0].cmd[0] = upstream[0];
		// list[0].cmd[0] = "cdfgfd";

		list[0].cmd[1] = upstream[1];
		// printf("%s\n %s\n", upstream[0], upstream[1]);																				 // list[0].cmd[2] = upstream[2];
		// printf("%s\n %s %s %s\n", downstream[0], downstream[1], downstream[2], downstream[3]); // list[0].cmd[2] = upstream[2];

		// list[0].cmd[2] = upstream[2];

		// // list[0].next = &list[1];
		// // list[1].cmd[0] = "/usr/bin/wc";
		// // list[1].cmd[1] = "-l";
		list[0].next = &list[1];
		list[1].cmd[0] = downstream[0];
		// list[1].cmd[1] = "ff=ff";

		// list[1].cmd[1] = downstream[1];

		// ///
		list[1].next = &list[2];

		list[2].cmd[0] = downstream[1];
		// list[2].cmd[1] = downstream[2];
		list[2].next = &list[3];

		list[3].cmd[0] = downstream[2];

		// list[3].cmd[1] = downstream[4];
		// list[3].cmd = downstream[4];
		list->there_is_pipe = 0;
		list->cmd_nbr = 1;
		list->rd = 1;


		// if(list->rd == 1)
		// 			{
		// 					list->fd_out  = open("a.txt",  O_RDWR|O_CREAT|O_TRUNC, 0600);
		// 				dup2(list->fd_out, 1);
		// close(	list->fd_out);
		// 				// list->fd_out = 	list->rd_stdout ;
		// 			}
		if (downstream[0] == NULL)
		{ 
			// if (list->there_is_pipe == 0)
			int i = 0 ;
				// int builtin = is_builtin(list, 0);
				// if(builtin == 0)
				// {				
					
						if(list->rd == 1)
					{
					
							list->fd_out  = open("a.txt",  O_RDWR|O_CREAT|O_TRUNC, 0600);
						// dup2(list->fd_out, 1);
						// close(list->fd_out);
						// list->fd_out = 	list->rd_stdout ;
					}
			if(ft_is_built_in(list)  == 0)
			{

			// }
				
				if (fork() == 0)
				{
											dup2(list->fd_out, 1);

					ft_bin_usr_sbin(list);
				}

				wait(NULL);
				// if (WIFEXITED(g_status))
				// {
				// 	g_status = WEXITSTATUS(g_status);
				// }
			}
			// else
			// {
			// 	g_status = 127;
			// }
		}
		else
		{
			// if (list->there_is_pipe > 0)
			// {
				// list->rd_stdout  = open("a.txt",  O_RDWR|O_CREAT|O_APPEND, 0600);
								// list->rd_stdout  = open("a.txt",  O_RDWR|O_CREAT, 0600);


			ft_pipe(list);
		}
		}
	
	free(input);
}
/*

......
	int	input;
	int	output;
	int	i;

	i = 0;
	if (redir != NULL)
	{
		input = dup(0);
		output = dup(1);
		i = check redirect  ();
	}
	if (i == 0)
		exec builtin( );
	if (redir != NULL)
	{
		ft_dup2(input, 1);
		ft_dup2(output, 0);
		close(input);
		close(output);
	}

	........

	how many cmds = ft_lstsize(linked list);
	if (heredoc())
		return (1);
	if (how many cmds > 0)
	{
		pid = is_builtin(cmds->content);
		if (how many cmds== 1 && pid != 0)
			ft_builtin(cmds->content, envp, pid);
		else
		{
			if (how many cmds > 1)
				pfds = create_pipes(how many cmds - 1);
			pid = create_childs(cmds, pfds, envp);
			if (how many cmds> 1)
				close_pfds(pfds, how many cmds - 1);
			waitpid(pid, exit_status, 0);
			set exit status(how many cmds);
		}	
	}
	return (0);
	...........................................................
		if (!ft_strcmp(redir->type, "<"))
			fd_i = open_file(redir, fd_i, O_RDONLY, 0);
		else if (!ft_strcmp(redir->type, ">"))
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (!ft_strcmp(redir->type, ">>"))
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd_i == -1 || fd_o == -1)
			return (EXIT_FAILURE);

*/

