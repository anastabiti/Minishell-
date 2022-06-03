/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:28:19 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 13:10:15 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


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