/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:43:04 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/29 08:48:20 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

struct s_builtins ft_init(struct s_builtins blt)
{
	blt.echo = "echo";
	blt.cd = "cd";
	blt.pwd = "pwd";
	blt.export = "export";
	blt.unset = "unset";
	blt.env = "env";
	blt.exit = "exit";
	blt.cd_path = "..";
	return (blt);
}
