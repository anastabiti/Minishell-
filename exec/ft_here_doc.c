/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:14:58 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/20 09:04:38 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	here_doc(struct s_list *list)
{
	int i = 0;

	if (ft_strncmp(HEREDOC, list[0].type[0], 7) == 0)
	{
		int fd;
		char *line;
		fd = open("HERE", O_RDWR | O_CREAT | O_TRUNC, 0777);

		while (1)
		{
			signal(SIGINT, handler);
			signal(SIGQUIT, SIG_IGN);
		line = readline(">");
			if (ft_strncmp(line, "EOF", 3) == 0)
			{
				break ;
			}
			write(fd, line, ft_strlen(line));
            write(fd, "\n", 1);
			free(line);
		}
        free(line);
        return 0;
	}
	return (0);
}