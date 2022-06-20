/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/20 22:14:20 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int argc, char **argv)
{
	char	*line;
	char	**split;
	t_cmdl	*cmd;
	int		i;

	if (argc == 1)
	{
		while (1)
		{
			line = readline(PROMPT);
			// printf("%s\n", line);
			add_history(line);
			if (!check_err_pipe(line))
				continue;
			split = ft_split(line, '|');
			i = -1;
			while (split[++i])
			{
				split[i] = rm_spaces(split[i]);
				printf("%s\n", split[i]);
				// if (!check_valid(split[i]))
				// 	ft_pass_cmd();
			}
		}
	}
}