/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:42:04 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/27 20:02:00 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
