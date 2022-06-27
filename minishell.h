/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:10:47 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/27 08:36:13 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "./exec/parse.h"
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# include <dirent.h> // open dir
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/wait.h>
# define TRUE 1
# define RDOUT "rstdout"
# define RDIN "rstdin"
# define RDAPPEND "rstdappend"
# define HEREDOC "HEREDOC"

struct						s_builtins
{
	char					*echo;
	char					*cd;
	char					*pwd;
	char					*export;
	char					*unset;
	char					*env;
	char					*exit;
	char					*cd_path;
	char					*cmd[100];
};

struct						s_list
{
	struct s_builtins		*blt;
	char					*cmd[50];
	struct s_list			*next;
	int						fd_out;
	char					*input;
	char					**environ;
	int						i;
	int						cmd_nbr;
	int						there_is_pipe;
	int						cmd_iteration;
	int						rd_stdout;
	int						rd_out;
	char					*redir;
	int						r_input;
	int						fd_in;

	char					*fileout;
	char					*filein;
	int						fd[2];
	int						redirection_out;
	int						redirection_in;
	int						append_stdout;
	int						rd_ir;
	char					*type[50];
	char					*file[50];
	char					*delimiter[50];
	struct s_redirections	*rd;
	struct						s_envp * envp;

	// cd
};

struct						s_envp
{
	char					**environment;
	int envpitems;
};
typedef struct t_list
{
	char					*content;
	void					*next;
}							t_list;
static int					g_exit_status;

void						handler(int sig);
int							prompt_and_parse(char **upstream, char **downstream,
								char *line);
void						rl_replace_line(const char *text, int clear_undo);
void						rl_clear_history(void);
// Builtin Commands
int							ft_pwd(int fd_out);
int							builtcheck_1(t_cmdl *cmd, struct						s_envp * envp);
int							ftexit(t_cmdl *cmd);
int							builtcheck(t_cmdl *cmd);
int							ftcd(t_cmdl *cmd);
// void						ft_env(char **env, struct s_list *list);
void						ft_env(struct						s_envp * envp, t_cmdl *list);
// int							ft_echo(struct s_list *list, char *arg, int fd);
int							ft_echo(t_cmdl *list, int fd);
// int							ft_is_built_in(struct s_list *list);
int							ft_is_built_in(t_cmdl *list,struct						s_envp * envp);
int							ft_unset(struct						s_envp * envp);
int						ft_export(struct						s_envp * envp, t_cmdl *cmd);
// int							is_builtin(struct s_list *list, int i);
//exece
int							is_builtin(t_cmdl *list, int i);
// int							one_cmd(struct s_list *list);
int							one_cmd(t_cmdl *list, struct						s_envp * envp);
int							set_rd(struct s_list *list);
int							run_builtin(struct s_list *list);
/// redirections I/O
// int							redirections(struct s_list *list);
int							redirections(t_cmdl *list);
int							heredoc_without_cmd(struct s_list *list);
// Other
// int							ft_bin_usr_sbin(struct s_list *list);
t_list						*ft_lstnew(void *content);
int							ft_bin_usr_sbin(t_cmdl *list);
char						**ft_search_for_path(t_cmdl *list);
void						ftcheck_nopath(t_cmdl *list);
void						looping_through_split_path(t_cmdl *list, int i,
								char *bin, char *last);
char						**create_argv_for_execve(t_cmdl *list);
int							ft_check_programs(t_cmdl *list);
//env
void ft_copy_1st_env(struct						s_envp * envp, char **env);
// LIBFT
int							ft_isdigit(int c);
int							ft_atoi(const char *str);
char						*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack,
					const char *needle,
					size_t len);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
size_t						ft_strlen(const char *s);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
char						*ft_strchr(const char *s, int c);
static char					*ccleaner(char **arr);
static char					*fsubstr(char const *s, unsigned int start,
								size_t len, char **arr);
static size_t				countblocks(char const *s1, char delimiter);
char						**ft_split(char const *s, char c);
char						*ft_strdup(const char *s1);
void						*ft_memcpy(void *dst, const void *src, size_t n);
size_t						ft_strlcpy(char *dst, const char *src,
								size_t dstsize);
void						*ft_memmove(void *dst, const void *src, size_t len);
size_t						ft_strlen(const char *s);
int							ft_search(char *s, char *c, int lenght);
// output libft
void						ft_putstr_fd(char *s, int fd);
void						ft_putchar_fd(char c, int fd);
void						ft_putendl_fd(char *s, int fd);
// read input
char						*ft_read(char *input);
// pipes
void						ft_pipe(struct s_list *list);
// signals
void						handler(int sig);
// init data
struct s_list				*ft_init(struct s_list *blt);

#endif
