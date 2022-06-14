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
	if (ft_strncmp(list[i].cmd[i], "cd", 2) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i], "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i], "echo", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i], "env", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i], "exit", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i], "unset", 5) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd[i], "export", 6) == 0)
		return (0);
	return (3);
}
// not mine is from a course i use it to accelerate work

int	prompt_and_parse(char **upstream, char **downstream, char *line)
{
	downstream[0] = NULL;
	line = readline("MINISHELL BETA $ ");
	if (line == NULL)
	{
		write(2, "exit\n", 5);
		rl_clear_history();
		free(line);
		exit(1);
	}
	add_history(line);
	*upstream++ = strtok(line, " \t");
	while ((*upstream = strtok(NULL, " \t")))
	{
		if (strcmp(*upstream, "|") == 0)
		{
			*upstream = NULL;
			while ((*downstream++ = strtok(NULL, " |")))
				;
			return (1);
		}
		upstream++;
	}
	downstream[0] = NULL;
	return (1);
}

int	main(int ac, char **av, char **env)
{
	struct s_list	*list;
	char			*input;
	int				fd;
	char			*upstream[20], *downstream[20];
	int				i;

	(void)ac;
	(void)av;
	list = (struct s_list *)malloc(sizeof(struct s_list) * 4);
	list->blt = (struct s_builtins *)malloc(sizeof(struct s_builtins) * 412);
	fd = 1;
	list->environ = env;
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		list->input = ft_read(list->input);
		ft_init(list);
		//......... cmds with args and options
		list[0].cmd[0] = "pwd";
		list[0].REDIRECTION_OUT = 1;
		list[0].REDIRECTION_IN = 0;
		list[0].fileout = "FILEOUT1";
		list[0].filein = "simpleparser.c";
		list[0].cmd[1] = NULL;
		list[0].next = &list[1];
		list->redir = ">";
		list->there_is_pipe = 1;
		list->cmd_nbr = 1;
		list->rd_out = 0;
		list->r_input = 1;
		list->cmd_iteration = 0;
		//// next node
		list[1].REDIRECTION_OUT = 1;
		list[1].REDIRECTION_IN = 0;
		list[1].fileout = "FILEOUT2";
		list[1].filein = "1";
		list[1].next = &list[2];
		//// next node
		list[2].REDIRECTION_OUT = 1;
		list[2].REDIRECTION_IN = 0;
		list[2].fileout = "FILEOUT3";
		list[2].filein = "last";
		list[2].next = &list[3];
		list[3].next = NULL;
		////.....
		if (list->cmd_nbr == 1 && is_builtin(list, 0) == 0)
		{
			i = 0;
			redirections(list);
			ft_is_built_in(list);
	///.................................///
			if (list->REDIRECTION_OUT == 1)
			{
				close(list->fd_out);
			}
			if (list->REDIRECTION_IN == 1)
			{
				close(list->fd_in);
			}
	///.................................///

		}
		//...>>>>>>>>>>>>>>
		else
		{
	
			if (fork() == 0)
			{
			redirections(list);

	///.................................///
	int i = 0;
	while(list[i].next != NULL)
	{
	if (list[i].REDIRECTION_OUT == 1)
			{
				dup2(list->fd_out, 1);
			}	
	if (list[i].REDIRECTION_IN == 1)
			{
					dup2(list->fd_in, 0);
			}
			i++;
	}
///.................................///
				ft_bin_usr_sbin(list);
					if (list->REDIRECTION_OUT == 1)
			{
				close(list->fd_out);
			}
			if (list->REDIRECTION_IN == 1)
			{
				close(list->fd_in);
			}
			}
			wait(NULL);
		}
		if (list->cmd_nbr > 1)
		{
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

// old
/*
// int builtin = is_builtin(list, 0);
				// if(builtin == 0)
				// {
	// while (prompt_and_parse(upstream, downstream, list->input) > 0)
			// if (list->there_is_pipe == 0)

 list[0].cmd[0] = "cdfgfd";

		list[0].cmd[1] = upstream[1];
		// printf("%s\n %s\n", upstream[0],
																									upstream[1]);																					// list[0].cmd[2] = upstream[2];
		// printf("%s\n %s %s %s\n", downstream[0], downstream[1],
				downstream[2], downstream[3]); // list[0].cmd[2] = upstream[2];

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
		// if(list->rd == 1)
		// 			{
		// 					list->fd_out  = open("a.txt",
										O_RDWR|O_CREAT|O_TRUNC, 0600);
		// 				dup2(list->fd_out, 1);
		// close(	list->fd_out);
		// 				// list->fd_out = 	list->rd_stdout ;
		// 			}

// if (WIFEXITED(g_status))
				// {
				// 	g_status = WEXITSTATUS(g_status);
				// }

			// if (list->there_is_pipe > 0)
			// {
				// list->rd_stdout  = open("a.txt",  O_RDWR|O_CREAT|O_APPEND,
						0600);
								// list->rd_stdout  = open("a.txt",
											O_RDWR|O_CREAT, 0600);
								// else
			// {
			// 	g_status = 127;
			// }
			// dup2(list->fd_out, 1);
						// close(list->fd_out);
						// list->fd_out = 	list->rd_stdout ;
						.....

		*/
