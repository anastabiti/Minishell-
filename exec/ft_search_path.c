/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 09:58:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/26 10:03:12 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_search_for_path(t_cmdl *list)
{
	int		x;
	char	**new;
	int		i;
	int		r;

	x = 0;
	while (!(ft_strnstr(list->environ[x], "PATH=", ft_strlen("PATH="))))
	{
		x++;
		if (list->environ[x] == NULL)
			return (NULL);
	}
	new = ft_split(list->environ[x], ':');
	i = 0;
	r = ft_strlen(new[0]);
	if (ft_search(new[0], "PATH=", ft_strlen("PATH=")) == 1)
	{
		while (i < r)
		{
			new[0][i] = new[0][i + 5];
			i++;
		}
	}
	new[i] = NULL;
	return (new);
}

void	ftcheck_nopath(t_cmdl *list)
{
	list->new = ft_search_for_path(list);
	if (list->new == NULL)
	{
		printf("MINISHELL : %s No such file or directory\n",
			list[list->cmd_iteration].cmd);
		exit(127);
	}
}

void	looping_through_split_path(t_cmdl *list, int i, char *bin, char *last)
{
	while (list->new[i])
	{
		last = ft_strjoin(bin, list[list->cmd_iteration].cmd);
		if (access(last, F_OK) == 0)
		{
			list->args_execve = create_argv_for_execve(list);
			execve(last, list->args_execve, list->environ);
			exit(127);
		}
		else
		{
			bin = ft_strjoin(list->new[i], "/");
			last = ft_strjoin(bin, list[list->cmd_iteration].cmd);
			i++;
		}
	}
}
