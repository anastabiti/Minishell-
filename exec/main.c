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
	struct s_list *list;
	char *input;
	int fd;
	char *upstream[20], *downstream[20];
	int i;

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
		list[0].cmd[0] = "caet";
		list[0].REDIRECTION_OUT = 0;
		list[0].REDIRECTION_IN = 1;
		list[0].fileout = "FILEOUT1";
		list[0].filein = "simpleparser.c";
		list[0].cmd[1] = NULL;
		list[0].next = &list[1];
		list->redir = ">";
		list->there_is_pipe = 1;
		list->cmd_nbr = 2;
		list->rd_out = 0;
		list->r_input = 1;
		list->cmd_iteration = 0;
		//// next node
		list[1].cmd[0] = "wc";
		list[1].REDIRECTION_OUT = 0;
		list[1].REDIRECTION_IN = 0;
		list[1].fileout = "FILEOUT2";
		list[1].filein = "1";
		list[1].next = &list[2];
		//// next node
		list[2].REDIRECTION_OUT = 0;
		list[2].REDIRECTION_IN = 0;
		list[2].fileout = "FILEOUT3";
		list[2].filein = "last";
		list[2].next = &list[3];
		list[3].next = NULL;
		if (one_cmd(list) == 0)
		{
			if (list->cmd_nbr > 1)
			{
				ft_pipe(list);
			}
		}
	}
	free(input);
}