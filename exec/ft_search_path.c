/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 09:58:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/02 17:57:55 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_search_for_path(t_cmdl *list,  struct s_envp *envp)
{
	int		x;
	char	**new;
	int		i;
	int		r;
	x = 0;
	while(x  < envp->envpitems)
	{
		if(ft_strncmp(envp->name[x], "PATH", 5) == 0)
		{
			break;
		}
		if(x == envp->envpitems)
			return NULL;
		x++;
	}
	
	new = ft_split(envp->environment[x], ':');
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

void	ftcheck_nopath(t_cmdl *list,  struct s_envp *envp)
{
	list->new = ft_search_for_path(list, envp);
	if (list->new == NULL)
	{
		printf("MINISHELL : %s No such file or directory\n",
			list[list->cmd_iteration].cmd);
		exit(127);
	}
}

void	looping_through_split_path(t_cmdl *list, int i, char *bin, char *last, struct s_envp *envp)
{
	i = 0;
	while (list->new[i])
	{
		last = ft_strjoin(bin, list[list->cmd_iteration].cmd);
		if (access(last, F_OK) == 0)
		{
			list->args_execve = create_argv_for_execve(list);
			execve(last, list->args_execve, envp->environment);
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

int	ft_search(char *s, char *c, int lenght)
{
	int	i;

	i = 1;
	while (i < lenght)
	{
		if (s[i] == c[i])
		{
			i++;
			if (i == lenght)
			{
				return (1);
			}
		}
		else
			return (0);
	}
	return (0);
}
