/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:40:50 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/29 11:13:17 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_move_quotes(const char *s, int *ind, int dq)
{
	while (s[*ind])
	{
		(*ind)++;
		if (dq && s[*ind] == '"')
			return ;
		else if (!dq && s[*ind] == '\'')
			return ;
	}
}

int	token_type(char *token_val)
{
	if (!ft_strcmp(token_val, "\""))
		return (D_QUOTE);
	else if (!ft_strcmp(token_val, "'"))
		return (S_QUOTE);
	else if (!ft_strcmp(token_val, "<<"))
		return (IN_D_RED);
	else if (!ft_strcmp(token_val, "<"))
		return (IN_RED);
	else if (!ft_strcmp(token_val, ">>"))
		return (OUT_D_RED);
	else if (!ft_strcmp(token_val, ">"))
		return (OUT_RED);
	else if (!ft_strcmp(token_val, "|"))
		return (PIPE);
	return (WORD);
}

void	ft_fill_token(t_token **token, const char *s, int  n_token)
{
	t_token	*t;
	int		j;
	int		i;
	int		start;

	t = *token;
	i = 1;
	j = 0;
	start = 0;
	while (j < n_token)
	{
		// printf("hi %s\n", s + i);
		while (s[i])
		{
			while (ft_is_white_space(s[i]))
				i++;
			start = i - 1;
			while (!ft_is_white_space(s[i]))
				i++;
			t[j].val = ft_substr(s, start, i - start);
			t[j].type = token_type(t[j].val);
			// if (s[i] == '"' || s[i] == '\'')
			// {
			// 	ft_move_quotes(s, &i, s[i] == '"');
			// 	t[j].val = ft_substr(s, start, i - start);
			// 	t[j].type = token_type(t[j].val);
			// 	start = i++ + 1;
			// 	break;
			// }
			// else if (!ft_is_white_space(s[i]) && ft_is_white_space(s[i - 1]))
			// {
			// 	while (s[i] && ft_isalnum(s[i]))
			// 		i++;
			// 	printf("we stop in %d\n", i);
			// 	t[j].val = ft_substr(s, start, i - start);
			// 	t[j].type = token_type(t[j].val);
			// 	start = i++ + 1;
			// 	break;
			// }
			i++;
		}
		printf("type is %d -- value is : %s\n", t[j].type, t[j].val);
		j++;
	}
}

void	ft_token(char *s)
{
	t_token	*token;
	int		n_token;
	int		i;

	n_token = 1;
	i = 1;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			ft_move_quotes(s, &i, s[i] == '"');
			n_token++;
		}
		else if (!ft_is_white_space(s[i]) && ft_is_white_space(s[i - 1]))
			n_token++;
		i++;
	}
	token = (t_token *)malloc(sizeof(t_token)* n_token);
	if (!token)
		return ;
	// printf("fill token start\n");
	ft_fill_token(&token, s, n_token);
	i = 0;
	// while (i < n_token)
	// {
		// printf("type is %d -- value is : %s\n", token[i].type, token[i].val);
	// 	i++;
	// }
	// printf("%d\n", n_token);
}