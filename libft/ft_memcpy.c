/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:39:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/01 13:04:30 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*castdest;
	const char	*castsrc;

	castdest = dst;
	castsrc = src;
	if (!castsrc && !castdest)
		return (NULL);
	while (n--)
		*castdest++ = *castsrc++;
	return (dst);
}
