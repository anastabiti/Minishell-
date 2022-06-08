/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:06:50 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/05 11:10:54 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_echo(char *arg, int fd)
{
	// if(you pass -n you must remove newline )
	// ft_putendl_fd(arg, fd);
	int len = ft_strlen(arg);

	write(fd, arg, len);
	write(fd, "\n", 1);

	return 0;
}

int ft_is_built_in(struct s_list *list)
{
	char **vr = list->environ;
	int i = 0;
	if (ft_strncmp(list[0].cmd[0], list->blt->echo, 4) == 0)
	{
		ft_echo(list[0].cmd[1], list->fd_out);
		return 1;
	}
	else if (ft_strncmp(list[0].cmd[0], list->blt->cd, 2) == 0)
	{
		if (chdir(list[0].cmd[1]) == -1) // // mkrim will provide me with FULL path to CD
		{
			// printf("Minishell: cd: %s: No such file or directory\n", list->blt->cd_path);

			char *error = "Minishell: cd: No such file or directory\n";
			int len = ft_strlen(error);
			write(2, error, len);
		}
		return 1;
	}
	else if (ft_strncmp(list[0].cmd[0], list->blt->export, 6) == 0)
	{
		ft_export(vr);
		return 1;
	}
	else if (ft_strncmp(list[0].cmd[0], list->blt->unset, 5) == 0)
	{
		ft_unset(vr);
		return 1;
	}
	////////////////////////////////////////////////////////////////////////
	// else if (ft_strncmp(list[0].cmd[0], list->blt->env, 3) == 0) // prints out the names and values of the variables in the environment,
	// {
	// 	ft_unset(vr);
	// 	return 1;
	// }
	////////////////////////////////////////////////////////////////////////
	else if (ft_strncmp(list[0].cmd[0], list->blt->env, 3) == 0) // prints out the names and values of the variables in the environment,
	{
		ft_env(list->environ, list);

		return 1;
	}
	else if (ft_strncmp(list[0].cmd[0], list->blt->pwd, 3) == 0)
	{
		ft_pwd(list->fd_out);
		return 1;
	}
	// else if (ft_strncmp(list->input, "$?", 2) == 0)
	// {
	// 	printf("%d\n", g_status);
	// 	return 1;
	// }
	else if (ft_strncmp(list[0].cmd[0], "exit", 4) == 0)
	{
		printf("exit\n");
		free(list->input);
		exit(0);
	}
	return 0;
}

int ft_pwd(int fd_out)
{
	char pw[PATH_MAX];
	char *pwd = getcwd(pw, PATH_MAX);
	// ft_putendl_fd(pw, fd_out);
	int len = ft_strlen(pwd);
	write(fd_out, pwd, len);
	write(fd_out, "\n", 1);

	return 1;
}