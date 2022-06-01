/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:05:14 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/01 13:00:54 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char *ccleaner(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
	return (NULL);
}

static char *fsubstr(char const *s, unsigned int start, size_t len, char **arr)
{
	char *substr;

	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (ccleaner(arr));
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

static size_t countblocks(char const *s1, char delimiter)
{
	size_t l;

	l = 0;
	while (*s1 != '\0')
	{
		if (*s1 != delimiter)
		{
			l++;
			while (*s1 != '\0' && *s1 != delimiter)
				s1++;
		}
		else
			s1++;
	}
	return (l);
}

char **ft_split(char const *s, char c)
{
	size_t index;
	size_t i;
	char **ptr;
	const char *spl;

	i = 0;
	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (countblocks(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		spl = s;
		index = 0;
		while (s[index] && s[index] != c)
			index++;
		s = s + index;
		if (*(s - 1) != c)
			ptr[i++] = fsubstr(spl, 0, index, ptr);
	}
	ptr[i] = NULL;
	return (ptr);
}
