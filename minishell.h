/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:10:47 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/24 11:58:31 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <limits.h>
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#include <sys/wait.h>
#include <dirent.h> // open dir

struct s_builtins
{
	char *echo;
	char *cd;
	char *pwd;
	char *export;
	char *unset;
	char *env;
	char *exit;
	char *cd_path;
};

void handler(int sig);
void rl_replace_line(const char *text, int clear_undo);
void rl_clear_history(void);
// Builtin Commands
void ft_pwd(void);
void ft_env(char **env);
char *ft_echo(char *arg);
int ft_is_built_in(struct s_builtins blt, char *input, char **env);
int ft_unset(char **env);
int ft_export(char **env);
// LIBFT
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlen(const char *s);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strchr(const char *s, int c);
#endif