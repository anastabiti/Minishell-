/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/06 20:00:31 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

void	lexer(char *line)
{
	t_cmdl	cmd;
	int		i;

	i = 0;
	while (1)
	{
		while (is_white_space(line[i]))
			i++;
	}
}

int main(int argc, char **argv)
{
	char	*line;

	if (argc == 1)
	{
		while (1)
		{
			line = readline("Minishell $");
			printf("%s\n", line);
			lexer(line);
		}
	}
}
