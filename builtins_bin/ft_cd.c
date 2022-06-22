/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:16:36 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 15:13:17 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*findhome;
	char	*error;
	int		len;

	// if (chdir(av[1]) == -1)
	// {
	// 	write(2, "Cd failed\n", 10);
	// 	exit(112);
	// }
	// return (0);
	// findhome = ;
	while (*env)
	{
		if (ft_strnstr(*env, "HOME=", 5))
		{
			findhome = *env;
			printf("%s\n", findhome);
		}
		env++;
	}
	if (findhome == NULL)
	{
		g_exit_status = 1;
		error = "Minishell: cd: HOME not set\n";
		len = ft_strlen(error);
		write(2, error, len);
	}
	// if (list->cmd[2] != NULL)
	// {
	// 	printf("Minishell: cd: too many arguments\n");
	// }
	if (chdir(av[1]) == -1)
	{
		g_exit_status = 1;
		error = "Minishell: cd: No such file or directory\n";
		len = ft_strlen(error);
		write(2, error, len);
	}
}
