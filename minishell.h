/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:10:47 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/21 09:15:46 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <limits.h>
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# include <sys/wait.h>

struct s_builtins
{
	char	*echo;
	char	*cd;
	char	*pwd;
	char	*export;
	char	*unset;
	char	*env;
	char	*exit;
	char	*cd_path;
};

char	*ft_echo(char *arg);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_pwd(char *arg);
void	ft_env(char **env);
int		ft_is_built_in(struct s_builtins blt, char *input, char **env);
void handler(int sig);
void rl_replace_line(const char *text, int clear_undo);;
#endif