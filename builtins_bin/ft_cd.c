/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:27:42 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/31 09:58:57 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int ac, char **av)
{
	if (chdir(av[1]) == -1) // // mkrim will provide me with FULL path to CD
	{
		printf("Minishell: cd: %s: No such file or directory\n", av[1]);
	}
	

}