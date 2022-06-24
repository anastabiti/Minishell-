/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/24 15:13:17 by mkarim           ###   ########.fr       */
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
			line = readline(PROMPT);
			add_history(line);
			// if (!check_err_pipe(line) || !check_valid(line))
			// 	continue;
			i = -1;
			while (line[++i])
				if (line[i] == '|')
					pipe++;
			cmd = (t_cmdl *)malloc(sizeof(t_cmdl) * (pipe));
			if (!cmd)
				return (0);
			i = -1;
			start = 0;
			int c = 0;
			int j = 0;
			while (j < pipe)
			{
				cmd[i].cmd = NULL;
				cmd[i].args = NULL;
				cmd[i].in_red = NULL;
				cmd[i].out_red = NULL;
				while (line[++i])
				{
					if (line[i] != ' ' && (line[i] < 9 || line[i] > 13))
						break;
				}
				while (line[++i])
				{
					if (line[i] == ' ')
					{
						cmd[j].cmd = ft_substr(line, start, i - start);
						start = i + 1;
						break;
					}
				}
				while (line[++i])
				{
					if (line[i] == '|' || line[i] == '<' || line[i] == '>')
					{
						cmd[j].args = ft_substr(line, start, i - start);
						start = i + 1;
						break;
					}
				}
				if (line[i - 1] == '>' || line[i] == '>')
				{
					while (line[++i])
					{
						if (line[i] == '|')
						{
							cmd[j].out_red = ft_substr(line, start, i - start);
							start = i + 1;
							break;
						}
					}
				}
				if (line[i - 1] == '<' || line[i] == '<')
				{
					while (line[++i])
					{
						if (line[i] == '|')
						{
							cmd[j].in_red = ft_substr(line, start, i - start);
							start = i + 1;
							break;
						}
					}
				}
				j++;
			}
			i = 0;
			j = 0;
			while (i < pipe)
			{
				printf("%d -- %s -- %s -- %s  %s\n", i , cmd[i].cmd, cmd[i].args, cmd[i].in_red, cmd[i].out_red);
				i++;
			}
			// while (line[++i])
			// {
			// 	if (line[i] == '<' || line[i] == '>' || line[i] == ' ' || line[i] == '\t' || line[i] == '|' || !line[i + 1])
			// 	{
			// 		//ft_add_back(&cmd, ft_substr(line, start, i - start - 1));
			// 		printf("%s", ft_substr(line, start, i - start + !line[i + 1]));
			// 		start = i + 1;
			// 		c++;
			// 	}
			// }
			printf("%d\n", c);
		}
	}
}
