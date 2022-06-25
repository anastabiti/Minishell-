/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/25 10:42:21 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_cmdl	*cmd;
	int		start;
	int		i;
	int		pipe = 1;
	

	if (argc == 1)
	{
		while (1)
		{
			pipe = 1;
			line = readline(PROMPT);
			add_history(line);
			if (!ft_strlen(line) || !check_err_pipe(line) || !check_valid(line))
				continue;
			i = -1;
			while (line[++i])
				if (line[i] == '|')
					pipe++;
			cmd = (t_cmdl *)malloc(sizeof(t_cmdl) * (pipe));
			if (!cmd)
				return (0);
			i = -1;
			start = 0;
			int j = 0;
			while (j < pipe)
			{
				cmd[j].cmd = NULL;
				cmd[j].args = NULL;
				cmd[j].in_red = NULL;
				cmd[j].out_red = NULL;
				i++;
				while (line[i])
				{
					if (line[i] != ' ' && (line[i] < 9 || line[i] > 13))
						break;
					i++;
				}
				while (line[i])
				{
					if (line[i] == ' ' || !line[i + 1])
					{
						cmd[j].cmd = rm_spaces(ft_substr(line, start, i - start + !line[i + 1]));
						start = i + 1;
						break;
					}
					i++;
				}
				while (line[i])
				{
					if (line[i] == '|' || line[i] == '<' || line[i] == '>' || !line[i + 1])
					{
						cmd[j].args = ft_split(rm_spaces(ft_substr(line, start, i - start + !line[i + 1])), ' ');
						start = i + 1;
						break;
					}
					i++;
				}
				if (line[i - 1] == '>' || line[i] == '>')
				{
					while (line[i])
					{
						if (line[i] == '|' || !line[i + 1])
						{
							cmd[j].out_red = rm_spaces(ft_substr(line, start, i - start + !line[i + 1]));
							start = i + 1;
							break;
						}
						i++;
					}
				}
				if (line[i - 1] == '<' || line[i] == '<')
				{
					while (line[i])
					{
						if (line[i] == '|' || !line[i + 1])
						{
							cmd[j].in_red = rm_spaces(ft_substr(line, start, i - start + !line[i + 1]));
							start = i + 1;
							break;
						}
						i++;
					}
				}
				j++;
			}
			i = 0;
			j = 0;
			while (i < pipe)
			{
				printf("%d -- %s -- %s -- %s -- %s\n", i , cmd[i].cmd, cmd[i].args[0], cmd[i].in_red, cmd[i].out_red);
				i++;
			}
		}
	}
}
