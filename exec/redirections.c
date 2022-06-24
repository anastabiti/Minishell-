/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asus <asus@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:50:59 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/24 20:23:28 by asus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"


int	redirections(struct s_list *list)
{
	int i = 0;
	int input;
	int output;
	while (list[0].type[i] != NULL)
	{
		// input = dup(0);
		// output = dup(1);
		if (ft_strncmp(list[0].type[i], RDOUT, 7) == 0)
		{
			list->fd_out = open(list[0].file[i], O_RDWR | O_CREAT | O_TRUNC,
					0600);
			if (list->fd_out == -1)
			{
				printf("bash: No such file or directory\n");
			}
		}
		if (ft_strncmp(list[0].type[i] , RDIN, 6) == 0)
		{	
			list->fd_in = open(list[0].file[i], O_RDONLY, 0);
			if (list->fd_in == -1)
			{
				printf("bash: No such file or directory\n");
			}
		}
		if (ft_strncmp(list[0].type[i] , RDAPPEND, 10) == 0)
		{
			list->fd_out = open(list[0].file[i], O_RDWR | O_CREAT | O_APPEND, 0600);	
		}
		if (ft_strncmp(list[0].type[i] , HEREDOC, 7) == 0)
		{
			list->fd_in = open("f1", O_RDWR | O_CREAT | O_TRUNC, 0600);	
		}
	

		i++;
	}
	return (0);
}
int	is_builtin(t_cmdl *list, int i)
{
	if (list[i].cmd == NULL)
		return (0);
	if (ft_strncmp(list[i].cmd , "cd", 2) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd , "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd , "echo", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd , "env", 3) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd , "exit", 4) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd , "unset", 5) == 0)
		return (0);
	else if (ft_strncmp(list[i].cmd , "export", 6) == 0)
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
