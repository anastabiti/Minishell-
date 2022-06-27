/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:33:31 by mkarim            #+#    #+#             */
/*   Updated: 2022/01/13 21:19:25 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbofl(char *s, char c)
{
	int		l;
	int		i;

	i = 0;
	l = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			l++;
		i++;
	}
	return (l);
}

static	char	**remplissage(char **p, char *s, char c, int l)
{
	int		i;
	int		j;
	int		cl;

	i = 0;
	j = 0;
	cl = 0;
	while (i < l)
	{
		cl = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			p[i][cl] = s[j];
			j++;
			cl++;
		}
		p[i][cl] = '\0';
		i++;
	}
	p[i] = 0;
	return (p);
}

static	char	**ft_free(char **p, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**p;
	t_variables	vb;

	if (!s)
		return (NULL);
	vb.l = nbofl((char *)s, c);
	p = (char **)malloc((vb.l + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	vb.i = -1;
	vb.j = 0;
	while (++(vb.i) < vb.l)
	{
		vb.cl = 0;
		while (s[vb.j] == c && s[vb.j])
			(vb.j)++;
		while (s[vb.j] && s[(vb.j)++] != c)
			(vb.cl)++;
		p[vb.i] = (char *)malloc((vb.cl + 1) * sizeof(char));
		if (!p[vb.i])
			return (ft_free(p, vb.i));
	}
	return (remplissage(p, (char *)s, c, vb.l));
}
