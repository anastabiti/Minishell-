/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:55:04 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/20 22:14:03 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_white_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*rm_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (s + i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_putchar(s[i]);
	}
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	check_err_pipe(char *s)
{
	if (s[ft_strlen(s) - 1] == '|')
	{
		ft_putstr(SNT_ERR);
		ft_putstr("|'\n");
		return (0);
	}
	return (1);
}

int	check_in_dir(char *s)
{
	int		i;
	int		dir;
	int		rep;

	i = -1;
	rep = 0;
	dir = 0;
	while (s[++i])
		if (s[i] == '<' || s[i] == '>')
			dir++;
	if (dir == ft_strlen(s))
	{
		ft_putstr(SNT_ERR);
		if (dir > 3)
		{
			rep = ft_min(3, dir - 3);
			i = -1;
			while (++i < rep)
				ft_putchar(s[0]);
			return (ft_putstr("'\n"), 0);
		}
		else
			return (ft_putstr("newline'\n"), 0);
	}
	return (1);
}

int	check_quotes(char *s)
{
	int	sngl_qt;
	int	dbl_quot;
	int	i;

	sngl_qt = 0;
	dbl_quot = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\'')
			sngl_qt++;
		else if (s[i] == '"')
			dbl_quot++;
	}
	if (sngl_qt % 2 || dbl_quot % 2)
		return (ft_putstr("Not closed quotes\n"), 0);
	return (1);
}

int	check_dir_with_file(char *s)
{
	if (s[ft_strlen(s) - 1] == '<' || s[ft_strlen(s) - 1] == '>')
	{
		ft_putstr(SNT_ERR);
		ft_putstr(">'\n");
		return (0);
	}
	return (1);
}

int	check_valid(char *s)
{
	if (!check_in_dir(s))
		return (0);
	if (!check_quotes(s))
		return (0);
	if (!check_dir_with_file(s))
		return (0);
	return (1);
}

void	ft_pass_cmd()
{
	
}