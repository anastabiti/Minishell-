/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:06:50 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/20 14:11:42 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_echo(char *arg)
{
	// if(you pass -n you must remove newline )
	printf("%s\n", arg);
	return arg;
}

// char *ft_pwd(char *arg)
// {

// }
int ft_is_built_in(struct s_builtins blt, char *input, char **env)
{
	char **vr = env;
	int i = 0;
	if (ft_strncmp(input, blt.echo, 4) == 0)
	{
		ft_echo(&input[4]);
	}

	else if (ft_strncmp(input, blt.cd, 2) == 0)
	{
		chdir(blt.cd_path);
	}
	else if (ft_strncmp(input, blt.export, 6) == 0)
	{

		char *to_be_exported = "x=2312312312312312312312";
		while (vr[i] && !(strstr(vr[i], "x=")))
		{
			i++;
		}
		vr[i] = to_be_exported;
		vr[i + 1] = NULL;
	}
	else if (ft_strncmp(input, blt.unset, 5) == 0)
	{
		int x = 0;
		int i = 0;
		while (!(strstr(vr[x], "HOME=/Users/atabiti")) && vr[x] != NULL) // change it later
		{
			x++;
			if (vr[x] == NULL)
				return 0;
		}

		while (vr[i])
		{
			i++;
		}

		while (x < i)
		{
			vr[x] = vr[x + 1];
			x++;
		}
		vr[i - 1] = NULL;
	}
	////////////////////////////////////////////////////////////////////////
	else if (ft_strncmp(input, blt.env, 3) == 0) // prints out the names and values of the variables in the environment,
	{
		ft_env(vr);
	}
	// else if (ft_strncmp(input, "./mini", 6) == 0)
	// {
	// 	int di = fork();
	// 	if (di == 0)
	// 	{
	// 		execve(" ./minishell ", NULL, NULL);
	// 		printf("SUCESS \n");
	// 	}
	// 	waitpid(di, 0, 0);
	// }
	/////////////////////////////////////////////////////////////////////////////////
	else if (ft_strncmp(input, blt.pwd, 3) == 0)
	{
		char pw[PATH_MAX];
		printf("%s\n", getcwd(pw, PATH_MAX));
	}
	else if (ft_strncmp(input, "ls", 2) == 0)
	{
		int pid = fork();
		if (pid == 0)
		{
			char *a[] = {"ls", "-la", NULL};
			execve("/bin/ls", a, NULL);
		}
		waitpid(pid, 0, 0);
	}
	else if (ft_strncmp(input, "exit", 4) == 0)
	{
		printf("exit\n");
		exit(1);
	}
	return 0;
}
