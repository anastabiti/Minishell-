/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:28:24 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 13:05:20 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	unsigned char *sone;
// 	unsigned char *stwo;

// 	sone = (unsigned char *)s1;
// 	stwo = (unsigned char *)s2;
// 	while (n > 0)
// 	{
// 		if (*sone != *stwo)
// 			return (*sone - *stwo);
// 		sone++;
// 		stwo++;
// 		n--;
// 	}
// 	return (0);
// }
// char *ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t needlelenght;

// 	needlelenght = ft_strlen(needle);
// 	if (needlelenght == '\0')
// 		return ((char *)haystack);
// 	while (*haystack != '\0' && len >= needlelenght)
// 	{
// 		if (!ft_memcmp(haystack, needle, needlelenght))
// 			return ((char *)haystack);
// 		haystack++;
// 		len--;
// 	}
// 	return (NULL);
// }

// size_t ft_strlen(const char *s)
// {
// 	int i = 0;
// 	if (s == NULL)
// 	{
// 		return 0;
// 	}
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return i;
// }

int main(int ac, char **av, char **env)
{
	char *to_be_exported = av[1];
	int len;

	len = ft_strlen(to_be_exported);
	int i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], to_be_exported, len))
		{
			return 0;
		}
		i++;
	}
	env[i] = to_be_exported;
	env[i + 1] = NULL;
	return 0;
}