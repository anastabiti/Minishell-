/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:30:11 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 13:10:01 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	write(1, av[1], len);
	write(1, "\n", 1);
	return (0);
}
