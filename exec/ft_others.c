/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:24:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/04 11:02:57 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_bin_usr_sbin(struct s_list *list)
{
	char *bin;
	char *current;
	int i;
	char **new;
	char pw[PATH_MAX];
	int x = 0;
	current = getcwd(pw, PATH_MAX);

	int lenght = ft_strlen("PATH=");
	while (!(ft_strnstr(list->environ[x], "PATH=", lenght))) // search for PATH=
	{
		x++;
		if (list->environ[x] == NULL)
			return 0;
	}

	new = ft_split(list->environ[x], ':'); // split PATH= to seperate paths

	i = 0;
	int r = ft_strlen(new[0]);
	if (ft_search(new[0], "PATH=", ft_strlen("PATH=")) == 1) // remove PATH= from start of the sring
	{
		while (i < r)
		{
			new[0][i] = new[0][i + 5];
			i++;
		}
	}
	new[i] = NULL;
	// current = ft_strjoin(current, "/");
	// current = ft_strjoin(current, list[list->cmd_iteration].cmd[0]);
	// i = 0;
	// while (new[i])
	// {
	// 	printf("%s\n", new[i]);
	// 	i++;
	// }
	i = 0;
	bin = ft_strjoin(new[i], "/"); // add / to path in order to execute binaries
	while (new[i])
	{

		char *last = ft_strjoin(bin, list[list->cmd_iteration].cmd[0]);
		if (access(last, F_OK) == 0) // check each PATH to find the right binaries to run them
		{
			// char *cmd[] = {list[list->cmd_iteration].cmd[0], NULL};
			if (execve(last, list[list->cmd_iteration].cmd, list->environ) == -1)
				write(2, "exeve failed\n", 14);
			exit(1);
		}

		// else if (access(current, F_OK) == 0) // check each PATH to find the right binaries to run them
		// {

		// 	char *cmd[] = {list[list->cmd_iteration].cmd[0], NULL};
		// 	if (execve(current, cmd, list->environ) == -1)
		// 		write(2, "exeve failed\n", 14);
		// }

		else
		{
			bin = ft_strjoin(new[i], "/");
			last = ft_strjoin(bin, list[list->cmd_iteration].cmd[0]);

			i++;
		}
	}

	// write(2, "MINISHELL command not found\n", 28);

exit(1);
}