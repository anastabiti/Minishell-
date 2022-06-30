/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:14:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/27 20:02:52 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memmove(void *s1, void *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*temp;
	size_t			len;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	temp = s;
	len = n;
	if (d == s)
		return (d);
	else
	{
		while (d != s && len > 0)
		{
			s++;
			len --;
		}
		if (d == s)
			while (n-- > 0)
				d[n] = temp[n];
		else
			ft_memcpy(d, temp, n);
	}
	return (d);
}
