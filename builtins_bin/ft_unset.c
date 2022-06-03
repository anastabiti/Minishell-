/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:28:29 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/03 12:56:56 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needlelenght;

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

size_t ft_strlen(const char *s)
{
	int i = 0;
	if (s == NULL)
	{
		return 0;
	}
	while (s[i])
	{
		i++;
	}
	return i;
}
int main(int ac, char **av, char **env)
{
	int x = 0;
	char *to_be_unset;

	int i = 0;
	// to_be_unset = "VAR=EXPORETED"; // mkrim must provide me with the string  to  unset
	to_be_unset = av[1];
	// mkrim must provide me with the string  to  unset

	int lenght = ft_strlen(to_be_unset);
	while (!(ft_strnstr(env[x], to_be_unset, lenght)))
	{
		x++;
		if (env[x] == NULL)
			return 0;
	}
	while (env[i]) // N of env strings
	{
		i++;
	}
	while (x < i) // copy back backward when one is unset
	{
		env[x] = env[x + 1];
		x++;
	}
	env[i - 1] = NULL;
	return 0;
	return 0;
}