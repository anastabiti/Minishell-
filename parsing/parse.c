/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/07 09:35:35 by mkarim           ###   ########.fr       */
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
	t_cmdl	*tmp;

	tmp = cmd;
	new = ft_new_node(c, f, pipe);
	if (tmp == NULL)
		tmp = new;
	else
	{
		while (tmp->next == NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	print(t_cmdl *c)
{
	t_cmdl	*tmp;

	tmp = c;
	while (tmp)
	{
		printf("pipe %d --- cmd is %s ------ flag is %s\n", tmp->pipe, tmp->c, tmp->f);
		tmp = tmp->next;
	}
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
				f[j++] = line[i++];
			ft_add_back(&cmd, c, f, 0);
		}
		else if (line[i] == '|')
		{
			ft_add_back(&cmd, c, "", 0);
			ft_add_back(&cmd, c, "", 1);
		}
		// printf("Hello ----\n");
		// if (j)
		// {
		// 	ft_add_back(&cmd, c, "", 0);
		// 	j = 0;
		// }
		print(&cmd);
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
