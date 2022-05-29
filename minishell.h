/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:10:47 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/29 11:48:46 by atabiti          ###   ########.fr       */
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
struct s_list
{
	struct s_builtins *blt;
	char *cmd[50];
	struct s_list *next;
	int fd_out;
};

void handler(int sig);
void rl_replace_line(const char *text, int clear_undo);
void rl_clear_history(void);
// Builtin Commands
void ft_pwd(int fd_out);
void ft_env(char **env);
int ft_echo(char *arg, int fd);
int ft_is_built_in(struct s_list *list, char *input, char **env, int fd);
int ft_unset(char **env);
int ft_export(char **env);
// Other
int ft_bin_usr_sbin(char *input);
// LIBFT
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlen(const char *s);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strchr(const char *s, int c);
// output libft
void ft_putstr_fd(char *s, int fd);
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);
// read input
char *ft_read(char *input);

// signals
void handler(int sig);
// init data
struct s_list *ft_init(struct s_list *blt);

#endif