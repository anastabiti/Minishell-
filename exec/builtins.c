/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:06:50 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/29 09:52:59 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_echo(char *arg, int fd)
{
	// if(you pass -n you must remove newline )
	// printf("%s\n", arg);
	ft_putstr_fd(arg, fd);
	return 0;
}

int ft_is_built_in(struct s_builtins blt, char *input, char **env, int fd)
{
	char **vr = env;
	int i = 0;
	if (ft_strncmp(input, blt.echo, 4) == 0)
	{
		ft_echo(&input[4], fd);
		return 1;
	}
	else if (ft_strncmp(input, blt.cd, 2) == 0)
	{
		if (chdir(blt.cd_path) == -1) // // mkrim will provide me with FULL path to CD
		{
			printf("Minishell: cd: %s: No such file or directory\n", blt.cd_path);
		}
		return 1;
	}
	else if (ft_strncmp(input, blt.export, 6) == 0)
	{
		ft_export(vr);
		return 1;
	}
	else if (ft_strncmp(input, blt.unset, 5) == 0)
	{
		ft_unset(vr);
		return 1;
	}
	////////////////////////////////////////////////////////////////////////
	else if (ft_strncmp(input, blt.env, 3) == 0) // prints out the names and values of the variables in the environment,
	{
		ft_env(vr);
		return 1;
	}
	else if (ft_strncmp(input, blt.pwd, 3) == 0)
	{
		ft_pwd();
		return 1;
	}
	else if (ft_strncmp(input, "exit", 4) == 0)
	{
		printf("exit\n");
		free(input);
		exit(1);
	}
	return 0;
}

void ft_pwd(void)
{
	char pw[PATH_MAX];
	getcwd(pw, PATH_MAX);
	printf("%s\n", pw);
}