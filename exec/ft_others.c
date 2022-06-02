/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:24:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/02 09:17:24 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_bin_usr_sbin(struct s_list *list)
{
	char *bin;

	// char path[PATH_MAX];
	// char *main_path;
	// char *pwd = ft_strjoin(getcwd(path, PATH_MAX), "/");
	// main_path = ft_strjoin(pwd, list->input);
	int i;
	///
	char **new;

	///
	int x = 0;
	int lenght = ft_strlen("PATH=");
	while (!(ft_strnstr(list->environ[x], "PATH=", lenght)))
	{
		x++;
		if (list->environ[x] == NULL)
			return 0;
	}

	///
	new = ft_split(list->environ[x], ':');
	i = 0;
	while (new[i])
	{
		printf("%s\n", new[i]);
		i++;
	}
	i = 0;
	int r = ft_strlen("PATH=");
	if (ft_search(new[0], "PATH=", ft_strlen("PATH=")) == 1)
	{
		while (i < ft_strlen(new[0]) - 5)
		{
			new[0][i] = new[0][r];
			r++;
			i++;
		}
	}
	new[i] = NULL;
	printf("%s\n", new[0]);

	i = 0;
	bin = ft_strjoin(new[i], "/");
	while (new[i])
	{

		char *last = ft_strjoin(bin, list->input);
		if (access(last, F_OK) == 0)
		{
			char *cmd[] = {list->input, NULL};
			if (execve(last, cmd, NULL) == -1)
				write(2, "exeve failed\n", 14);
		}
		else
		{
			bin = ft_strjoin(new[i], "/");
			last = ft_strjoin(bin, list->input);

			i++;
		}
	}
	write(2, "MINISHELL command not found\n", 28);

	// if (access(bin, F_OK) == 0)
	// {
	// 	char *cmd[] = {list->input, NULL};
	// 	int idd = fork();
	// 	if (idd == 0)
	// 	{
	// 		execve(bin, cmd, NULL);
	// 	}
	// 	// waitpid(idd, 0, 0);
	// 	wait(0);
	// }
	// else if (access(userbin, F_OK) == 0)
	// {
	// 	char *cmd[] = {list->input, NULL};
	// 	int gg = fork();
	// 	if (gg == 0)
	// 	{
	// 		execve(userbin, cmd, NULL);
	// 	}
	// 	// waitpid(gg, 0, 0);
	// 	wait(0);
	// }
	// else if (access(list->input, F_OK) == 0)
	// {
	// 	char *cmd[] = {list->input, NULL};
	// 	int gg = fork();
	// 	if (gg == 0)
	// 	{
	// 		execve(list->input, cmd, NULL);
	// 	}
	// 	// waitpid(gg, 0, 0);
	// 	wait(0);
	// }
	// else if (access(main_path, F_OK) == 0)
	// {
	// 	char *cmd[] = {list->input, NULL};
	// 	int gg = fork();
	// 	if (gg == 0)
	// 	{
	// 		execve(main_path, cmd, NULL);
	// 	}
	// 	wait(0);
	// }
	// else if (access(sbin, F_OK) == 0)
	// {
	// 	if (fork() == 0)
	// 	{
	// 		execve(sbin, NULL, NULL);
	// 	}
	// 	wait(0);
	// }

	return 0;
}