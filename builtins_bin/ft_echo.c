/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:02:59 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 09:09:29 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, fd);
}
void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
int ft_echo(char *arg, int fd)
{
	// if(you pass -n you must remove newline )
	ft_putendl_fd(arg, fd);
	// ft_putstr_fd(arg, fd);
	return 0;
}

int main(int ac, char **av)
{
	if (!av[1])
	{
		ft_putendl_fd("", 1);
	}
	ft_echo(av[1], 1);
}