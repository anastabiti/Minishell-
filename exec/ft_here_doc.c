/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:14:58 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/22 09:09:17 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//<< EOF without command
void	handler_in_heredoc(int sig)
{
	if (sig == SIGINT)
		exit(1);
}
int	heredoc_without_cmd(struct s_list *list) //sigfault
{
	int i = 0;
	if (fork() == 0)
	{
		if (ft_strncmp(HEREDOC, list[0].type[0], 7) == 0)
		{
			// signal(SIGINT, handler_in_heredoc);
			// signal(SIGQUIT, SIG_IGN);
			int fd;
			char *line;
			fd = open("/tmp/tmpfiletowrite", O_RDWR | O_CREAT | O_TRUNC, 0777);

			while (1)
			{
				signal(SIGQUIT, SIG_IGN);
				signal(SIGQUIT, handler_in_heredoc);

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
			exit(0);
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		wait(&g_exit_status);
	}
	return (g_exit_status);
}