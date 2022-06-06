/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:46:57 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/22 14:57:46 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelenght;

	needlelenght = ft_strlen(needle);
	if (needlelenght == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len >= needlelenght)
	{
		if (!ft_memcmp(haystack, needle, needlelenght))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int i = 0;
	if (s == NULL)
	{
		return (0);
	}
	while (s[i])
	{
		i++;
	}
	return (i);
}