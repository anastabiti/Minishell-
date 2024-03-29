/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:55:04 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/05 22:50:17 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../minishell.h"
// #include "../libft/libft.h"



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



char	*rm_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (s + i);
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
		ft_putstr_fd(SNT_ERR, 2);
		ft_putstr_fd("|'\n", 2);
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
		ft_putstr_fd(SNT_ERR, 2);
		if (dir > 3)
		{
			rep = ft_min(3, dir - 3);
			i = -1;
			while (++i < rep)
				ft_putchar(s[0]);
			return (ft_putstr_fd("'\n", 1), 0);
		}
		else
			return (ft_putstr_fd("newline'\n", 1), 0);
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
		return (ft_putstr_fd("Not closed quotes\n", 1), 0);
	return (1);
}

int	check_dir_with_file(char *s)
{
	if (s[ft_strlen(s) - 1] == '<' || s[ft_strlen(s) - 1] == '>')
	{
		ft_putstr_fd(SNT_ERR, 1);
		ft_putstr_fd(">'\n", 1);
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

