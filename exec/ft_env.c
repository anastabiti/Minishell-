/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:50:22 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/24 22:20:25 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char **env, t_cmdl *list)
{
	char	**var;

	var = env;
	while (*var != NULL)
	{
		ft_putendl_fd(*var, list->fd_out);
		var++;
	}
}
