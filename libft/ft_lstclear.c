/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:08:42 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/27 19:53:38 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*holder;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		holder = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(holder, del);
	}
	*lst = NULL;
}
