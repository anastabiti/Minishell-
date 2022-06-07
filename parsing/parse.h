/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:56:03 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/07 09:14:58 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmdl {
	int				pipe;
	char			*c;
	char			*flag;
	struct s_cmdl	*next;
}		t_cmdl;


int		is_white_space(char c);
int		ft_is_alpha(char c);

#endif
