/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:24:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/25 10:38:47 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
// while (list[list->cmd_iteration].args[x] != NULL)
			// {
			// 	args[0] = list[list->cmd_iteration].cmd;
			// 	args[x + 1] = list[list->cmd_iteration].args[x];
			// 	printf(" %s      \n", args[x]);
			// 	x++;
			// }
			// args[x] = NULL;
*/

int	cmd_args_len(t_cmdl *list)
{
	int	len;

	while (list[list->cmd_iteration].args[len] != NULL)
	{
		len++;
	}
	return (len);
}

char	**create_argv_for_execve(t_cmdl *list)
{
	int		len;
	int		i;
	char	**argv;

	len = cmd_args_len(list);
	argv = malloc(sizeof(char **) * len);
	i = 0;
	while (i < len)
	{
		argv[0] = list[list->cmd_iteration].cmd;
		argv[i + 1] = list[list->cmd_iteration].args[i];
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

int	ft_check_programs(t_cmdl *list)
{
	char	**argv;
	int		x;

	x = 0;
	if (list[list->cmd_iteration].cmd[0] == '.'
		&& list[list->cmd_iteration].cmd[1] == '/')
	{
		argv = create_argv_for_execve(list);
		execve(list[list->cmd_iteration].cmd, argv, NULL);
		printf("Minishell : %s : No such file or directory\n",
				list[list->cmd_iteration].cmd);
		exit(127);
	}
	x = 0;
	if (list[list->cmd_iteration].cmd[0] == '/')
	{
		argv = create_argv_for_execve(list);
		execve(list[list->cmd_iteration].cmd, argv, NULL);
		printf("Minishell : %s : No such file or directory\n",
				list[list->cmd_iteration].cmd);
		exit(127);
	}
	return (0);
}

char	**ft_search_for_path(t_cmdl *list)
{
	int		x;
	int		lenght;
	char	**new;
	int		i;
	int		r;

	x = 0;
	lenght = ft_strlen("PATH=");
	while (!(ft_strnstr(list->environ[x], "PATH=", lenght)))
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

int	ft_bin_usr_sbin(t_cmdl *list)
{
	char	*bin;
	char	*current;
	int		i;
	char	**new;
	char	pw[PATH_MAX];
	char	*last;
	char	**args;

	current = getcwd(pw, PATH_MAX);
	//
	new = ft_search_for_path(list);
	if (new == NULL)
	{
		printf("MINISHELL : %s No such file or directory\n",
				list[list->cmd_iteration].cmd);
		return (0);
	}
	i = 0;
	bin = ft_strjoin(new[i], "/");
	while (new[i])
	{
		last = ft_strjoin(bin, list[list->cmd_iteration].cmd);
		if (access(last, F_OK) == 0)
		{
			args = create_argv_for_execve(list);
			execve(last, args, list->environ);
			exit(127);
		}
		else
		{
			bin = ft_strjoin(new[i], "/");
			last = ft_strjoin(bin, list[list->cmd_iteration].cmd);
			i++;
		}
		ft_check_programs(list);
	}
	// write(2, "MINISHELL command not found\n", 28);
	exit(127);
}
