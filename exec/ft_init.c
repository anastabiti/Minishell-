/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:43:04 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/04 10:58:35 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

struct s_list	*ft_init(struct s_list *list)
{
	list->blt->echo = "echo";
	list->blt->cd = "cd";
	list->blt->pwd = "pwd";
	list->blt->export = "export";
	list->blt->unset = "unset";
	list->blt->env = "env";
	list->blt->exit = "exit";
	list->blt->cd_path = "/biren/";
	return (list);
}
