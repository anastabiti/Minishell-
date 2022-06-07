/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/07 09:21:56 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

t_cmdl	*ft_new_node(char *c, char *f, int p)
{
	t_cmdl	*node;

	node = malloc(sizeof(t_cmdl));
	if (!node)
		return (node);
	if (p)
		node->pipe = p;
	else
	{
		node->pipe = p;
		node->c = c;
		node->f = f;
		node->next = NULL;
	}
	return (node);
}

void	ft_add_back(t_cmdl *cmd, char *c, char *f, int pipe)
{
	t_cmdl	*new;

	new = ft_new_node(c, f, pipe);
}

void	parser(char *line)
{
	t_cmdl	cmd;
	char	c[100];
	char	f[100];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (is_white_space(line[i]))
			i++;
		while (ft_is_alpha(line[i]))
			c[j++] = line[i++];
		while (is_white_space(line[i]))
			i++;
		if (line[i] == '-')
		{
			j = 0;
			while (ft_is_alpha(line[i]))
				flag[j++] = line[i++];
			ft_add_back(&cmd, c, f, 0);
		}
		else if (line[i] == '|')
		{
			ft_add_back(&cmd, c, "", 0);
			ft_add_back(&cmd, c, "", 1)
		}
		if (j)
		{
			ft_add_back(&cmd, c, "");
			j = 0;
		}
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
			parser(line);
		}
	}
}
