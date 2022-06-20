/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:14:58 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/20 09:23:07 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//<< EOF without command
int	heredoc_without_cmd(struct s_list *list) //sigfault
{
	int i = 0;
	if (fork() == 0)
	{
		if (ft_strncmp(HEREDOC, list[0].type[0], 7) == 0)
		{
			int fd;
			char *line;
			fd = open("HERE", O_RDWR | O_CREAT | O_TRUNC, 0777);
			signal(SIGINT, handler);
			signal(SIGQUIT, SIG_IGN);
			while (1)
			{
				line = readline(">");

				if (ft_strncmp(line, "EOF", 3) == 0)
				{
					break ;
				}
				if (line == NULL)
				{
					return (1);
				}
				write(fd, line, ft_strlen(line));
				write(fd, "\n", 1);
				free(line);
			}
			free(line);
			close(fd);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
			
	}
	return (0);
}