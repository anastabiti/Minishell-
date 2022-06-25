/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:56:03 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/24 22:20:51 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
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

typedef struct s_cmdl {
	char	*cmd;
	char	*args;
	char	*in_red;
	char	*out_red;
	//mine
	int cmd_iteration;
	int cmd_nbr;
	char					*type[50];
	char					*file[50];
		int						fd_out;
			int						fd_in;
				char					**environ;

//....
}		t_cmdl;

int		is_white_space(char c);
int		ft_is_alpha(char c);
char    *rm_spaces(char *s);
int		check_valid(char *s);
void	ft_pass_cmd();
int	check_err_pipe(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
