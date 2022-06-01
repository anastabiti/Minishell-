/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:24:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/01 13:31:46 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_bin_usr_sbin(struct s_list *list)
{
	char *bin;
	char *userbin;
	char *sbin;
	sbin = ft_strjoin("/sbin/", list->input);
	bin = ft_strjoin("/bin/", list->input);
	userbin = ft_strjoin("/usr/bin/", list->input);
	char path[PATH_MAX];
	char *main_path;
	char *pwd = ft_strjoin(getcwd(path, PATH_MAX), "/");
	main_path = ft_strjoin(pwd, list->input);
	if (ft_strncmp("123", list->input, 3) == 0)
	{
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
		char **new = ft_split(list->environ[x], ':');
		int i = 0;
		while (new[i])
		{
			printf("%s      \n", new[i]);
			i++;
		}
	}
	if (access(bin, F_OK) == 0)
	{
		char *cmd[] = {list->input, NULL};
		int idd = fork();
		if (idd == 0)
		{
			execve(bin, cmd, NULL);
		}
		// waitpid(idd, 0, 0);
		wait(0);
	}
	else if (access(userbin, F_OK) == 0)
	{
		char *cmd[] = {list->input, NULL};
		int gg = fork();
		if (gg == 0)
		{
			execve(userbin, cmd, NULL);
		}
		// waitpid(gg, 0, 0);
		wait(0);
	}
	else if (access(list->input, F_OK) == 0)
	{
		char *cmd[] = {list->input, NULL};
		int gg = fork();
		if (gg == 0)
		{
			execve(list->input, cmd, NULL);
		}
		// waitpid(gg, 0, 0);
		wait(0);
	}
	else if (access(main_path, F_OK) == 0)
	{
		char *cmd[] = {list->input, NULL};
		int gg = fork();
		if (gg == 0)
		{
			execve(main_path, cmd, NULL);
		}
		wait(0);
	}
	else if (access(sbin, F_OK) == 0)
	{
		if (fork() == 0)
		{
			execve(sbin, NULL, NULL);
		}
		wait(0);
	}

	return 0;
}