/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:56:03 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/01 09:06:43 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

typedef struct s_cmdl
{
	char	*cmd;
	char	**args;
	char	*in_red;
	char	*out_red;
	int		cmd_iteration;
	int		cmd_nbr;
	char	*type[50];
	char	*file[50];
	int		fd_out;
	int		fd_in;
	char	**environ;
	char	**args_execve;
	char	*findhome;
	char	**split;
	char	*error;
	int		len;
	char	**new;
	char	**myenvp;
	int		envlen;
	int		there_is_pipe;
	int		fd[2];
	char **envsplited;
	char **envvariables; 
	int envvarpos;
}			t_cmdl;

int			is_white_space(char c);
int			ft_is_alpha_mod(char c);
char		*rm_spaces(char *s);
int			check_valid(char *s);
void		ft_pass_cmd(void);
int			check_err_pipe(char *s);
// char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
