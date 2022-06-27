/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:42:04 by mkarim            #+#    #+#             */
/*   Updated: 2021/11/06 15:48:00 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc((n * size) * sizeof(char));
	if (!p)
		return (p);
	while (i < n * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
