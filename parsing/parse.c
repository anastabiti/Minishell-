/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/17 13:10:24 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

int main(int argc, char **argv)
{
	char	*line;
	char	**split;
	t_cmdl	*cmd;
	int		i;

	i = -1;
	if (argc == 1)
	{
		while (1)
		{
			line = readline("Minishell $ ");
			printf("%s\n", line);
			add_history(line);
			split = ft_split(line, '|');
			while (split[++i])
			{
				ft_lstadd_back(&cmd, ft_lstnew(split[i]));
			}
		}
	}
}
