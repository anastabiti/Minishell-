/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:28:27 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 13:10:22 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(int fd_out)
{
	char	pw[PATH_MAX];
	char	*pwd;
	int		len;

	pwd = getcwd(pw, PATH_MAX);
	len = ft_strlen(pwd);
	write(fd_out, pwd, len);
	write(fd_out, "\n", 1);
	return (1);
}

int	main(int ac, char **av)
{
	ft_pwd(1);
	return (0);
}
