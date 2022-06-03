/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:28:27 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 12:32:53 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t ft_strlen(const char *s)
{
	int i = 0;
	if (s == NULL)
	{
		return 0;
	}
	while (s[i])
	{
		i++;
	}
	return i;
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
int main(int ac, char **av)
{
	ft_pwd(1);
	return 0;
}
