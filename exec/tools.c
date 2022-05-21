/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:19:32 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/21 10:50:40 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	while ((s1[index] != 0 || s2[index] != 0) && index < n)
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *sone;
	unsigned char *stwo;

	sone = (unsigned char *)s1;
	stwo = (unsigned char *)s2;
	while (n > 0)
	{
		if (*sone != *stwo)
			return (*sone - *stwo);
		sone++;
		stwo++;
		n--;
	}
	return (0);
}
char *ft_strchr(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}
