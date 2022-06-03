/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:28:19 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 12:40:26 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, fd);
}

void ft_putendl_fd(char *s, int fd)

{
	if (!s)
		return;
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

int main(int ac, char **av, char **env)
{

	char **var = env;
	while (*var != NULL)
	{
		// printf("%s\n", *var);
		ft_putendl_fd(*var, 1);
		var++;
	}
	return 0;
}