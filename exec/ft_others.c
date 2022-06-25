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
comments 
	while (!(ft_strnstr(list->environ[x], "PATH=", lenght))) // search for PATH=
	new = ft_split(list->environ[x], ':'); // split PATH= to seperate paths
	if (ft_search(new[0], "PATH=", ft_strlen("PATH=")) == 1)
	// remove PATH= from start of the sring
	// current = ft_strjoin(current, "/");
	// current = ft_strjoin(current, list[list->cmd_iteration].cmd[0]);
	// i = 0;
	// while (new[i])
	// {
	// 	printf("%s\n", new[i]);
	// 	i++;
	// }
		bin = ft_strjoin(new[i], "/"); // add
			/ to path in order to execute binaries
char	*last = ft_strjoin(bin, list[list->cmd_iteration].cmd[0]);
		if (access(last, F_OK) == 0)
		// check each PATH to find the right binaries to run them
		{
			// char *cmd[] = {list[list->cmd_iteration].cmd[0], NULL};
			if (execve(last, list[list->cmd_iteration].cmd, list->environ) ==
				-1)
				write(2, "exeve failed\n", 14);
			exit(1);
		}

		// else if (access(current, F_OK) == 0)
			// check each PATH to find the right binaries to run them
		// {

		// 	char *cmd[] = {list[list->cmd_iteration].cmd[0], NULL};
		// 	if (execve(current, cmd, list->environ) == -1)
		// 		write(2, "exeve failed\n", 14);
		
		// }
*/

int	ft_bin_usr_sbin(t_cmdl *list)
{
	char *bin;
	char *current;
	int i;
	char **new;
	char pw[PATH_MAX];
	int x;
	int lenght;
	int r;
	char *last;

	x = 0;
	current = getcwd(pw, PATH_MAX);
	lenght = ft_strlen("PATH=");
	while (!(ft_strnstr(list->environ[x], "PATH=", lenght)))
	{
		x++;
		if (list->environ[x] == NULL)
			return (0);
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

	i = 0;
	bin = ft_strjoin(new[i], "/");
	while (new[i])
	
	{
				char *args[212];
		last = ft_strjoin(bin, list[list->cmd_iteration].cmd);
		int x = 0;
		if (access(last, F_OK) == 0)
		{	
			while(list[list->cmd_iteration].args[x] != NULL)
			{
						args[0] = list[list->cmd_iteration].cmd  ;
			args[x + 1] = list[list->cmd_iteration].args[x];
			printf(" %s      \n" ,args[x]);
			x++;
			}
			args[x] = NULL;
			if (execve(last, args, list->environ) ==
				-1)
				write(2, "exeve dfailed\n", 14);
			exit(1);
		}
		else
		{
			bin = ft_strjoin(new[i], "/");
			last = ft_strjoin(bin,  list[list->cmd_iteration].cmd);
			i++;
		}
		///
		 if (list[list->cmd_iteration].cmd[0] == '.' && list[list->cmd_iteration].cmd[1] == '/')
		{
			// char *cmd[3] = {list[list->cmd_iteration].cmd,list[list->cmd_iteration].args[0], NULL};
			while(list[list->cmd_iteration].args[x] != NULL)
			{
						args[0] = list[list->cmd_iteration].cmd  ;
			args[x + 1] = list[list->cmd_iteration].args[x];
			printf(" %s\n" ,args[x]);
			x++;
			}
			args[x] = NULL;
			execve(list[list->cmd_iteration].cmd, args, NULL);
			printf("failed");
		}
		if (list[list->cmd_iteration].cmd[0] == '/')
		{
			// char *cmd[3] = {list[list->cmd_iteration].cmd,list[list->cmd_iteration].args[0], NULL};
			while(list[list->cmd_iteration].args[x] != NULL)
			{
						args[0] = list[list->cmd_iteration].cmd  ;
			args[x + 1] = list[list->cmd_iteration].args[x];
			printf(" %s\n" ,args[x]);
			x++;
			}
			args[x] = NULL;
			execve(list[list->cmd_iteration].cmd, args, NULL);
		}
		///
	}
	write(2, "MINISHELL command not found\n", 28);
	exit(127);
}