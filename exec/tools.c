/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:19:32 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/01 09:06:44 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

static int	nb_digits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] != 0 || s2[index] != 0) && index < n)
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sone;
	unsigned char	*stwo;

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

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	mer;
	size_t	lenght;
	char	*merge;

	mer = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	merge = (char *)malloc(sizeof(char) * lenght);
	if (!merge)
		return (NULL);
	while (*s1 != '\0')
	{
		merge[mer] = *s1;
		s1++;
		mer++;
	}
	while (*s2 != '\0')
	{
		merge[mer] = *s2;
		s2++;
		mer++;
	}
	merge[mer] = '\0';
	return (merge);
}


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

size_t	ft_strlen(const char *s)
{
	int		i;
	if(s == NULL)
	return 0;
	i = 0;
	while (s[i])
		i++;
	return (i);
}



char	*ft_itoa(int n)
{
	int		size;
	int		len;
	long	nb;
	char	*p;

	size = 0;
	if (n < 0)
		size = 1;
	len = nb_digits(n);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (p);
	nb = n;
	if (nb < 0)
		p[0] = '-';
	if (nb < 0)
		nb *= -1;
	p[len] = '\0';
	while (--len >= size)
	{
		p[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (p);
}
