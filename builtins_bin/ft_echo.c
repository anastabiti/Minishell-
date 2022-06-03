/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:30:11 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 10:55:54 by atabiti          ###   ########.fr       */
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
int main(int ac, char **av)
{
	int len = ft_strlen(av[1]);

	write(1, av[1], len);
	write(1, "\n", 1);

	return 0;
}