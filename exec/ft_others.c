/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:24:12 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/26 10:35:26 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_bin_usr(char *input)
{
	char *bin;
	char *userbin;
	bin = ft_strjoin("/bin/", input);
	userbin = ft_strjoin("/usr/bin/", input);
	char path[PATH_MAX];
	char *main_path = ft_strjoin(getcwd(path, PATH_MAX), "/");

	main_path = ft_strjoin(main_path, input);
	if (access(bin, F_OK) == 0)
	{
		char *cmd[] = {input, NULL};
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
		char *cmd[] = {input, NULL};
		int gg = fork();
		if (gg == 0)
		{
			execve(userbin, cmd, NULL);
		}
		// waitpid(gg, 0, 0);
		wait(0);
	}
	else if (access(main_path, F_OK) == 0)
	{
		char *cmd[] = {input, NULL};
		int gg = fork();
		if (gg == 0)
		{
			execve(main_path, cmd, NULL);
		}
		wait(0);
	}
	return 0;
}