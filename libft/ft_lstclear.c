/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:08:42 by mkarim            #+#    #+#             */
/*   Updated: 2021/11/12 11:37:27 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;

	last = *lst;
	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		last = *lst;
		del(last->content);
		free(last);
		(*lst) = (*lst)->next;
	}
}
