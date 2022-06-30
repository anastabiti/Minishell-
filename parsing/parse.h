/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:56:03 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/20 22:14:39 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "minishell $ "
# define PRE_ERR "minishell: "
# define SNT_ERR "minishell: syntax error near unexpected token `"

/* ----------- START STRUCT FOR SPLIT ----------- */

typedef struct s_variables
{
	int		l;
	int		i;
	int		j;
	int		cl;
}			t_variables;

/* ----------- END STRUCT FOR SPLIT ----------- */

typedef struct s_data {
	char	*cmd_line;
	int		num_cmd;
}		t_data;

size_t	ft_strlen(char *s);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
char	**ft_split(char const *s, char c);
int		is_white_space(char c);
int		ft_is_alpha(char c);
char    *rm_spaces(char *s);
int		check_valid(char *s);
void	ft_pass_cmd();
int		check_err_pipe(char *s);

#endif
