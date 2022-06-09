/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:10:47 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/05 08:50:39 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# include <signal.h>

# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# include <dirent.h> // open dir
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>

struct					s_builtins
{
	char				*echo;
	char				*cd;
	char				*pwd;
	char				*export;
	char				*unset;
	char				*env;
	char				*exit;
	char				*cd_path;
	char				*cmd[100];
};
struct					s_list
{
	struct s_builtins	*blt;
	char				*cmd[50];
	struct s_list		*next;
	int					fd_out;
	char				*input;
	char				**environ;
	int					i;
	int					cmd_nbr;
	int					there_is_pipe;
	int					cmd_iteration;
	int rd_stdout;
	int rd;
	char *redir;
	int r_input;
	int fd_in;

};

void					handler(int sig);
int						prompt_and_parse(char **upstream, char **downstream,
							char *line);
void					rl_replace_line(const char *text, int clear_undo);
void					rl_clear_history(void);
// Builtin Commands
int						ft_pwd(int fd_out);
void					ft_env(char **env, struct s_list *list);
int						ft_echo(char *arg, int fd);
int						ft_is_built_in(struct s_list *list);
int						ft_unset(char **env);
int						ft_export(char **env);
int	is_builtin(struct s_list *list, int i);
// Other
int						ft_bin_usr_sbin(struct s_list *list);
// LIBFT
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
size_t					ft_strlen(const char *s);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strchr(const char *s, int c);
static char				*ccleaner(char **arr);
static char				*fsubstr(char const *s, unsigned int start, size_t len,
							char **arr);
static size_t			countblocks(char const *s1, char delimiter);
char					**ft_split(char const *s, char c);
char					*ft_strdup(const char *s1);
void					*ft_memcpy(void *dst, const void *src, size_t n);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
void					*ft_memmove(void *dst, const void *src, size_t len);
size_t					ft_strlen(const char *s);
int						ft_search(char *s, char *c, int lenght);
// output libft
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
// read input
char					*ft_read(char *input);
// pipes
void						ft_pipe(struct s_list *list);
// signals
void					handler(int sig);
// init data
struct s_list			*ft_init(struct s_list *blt);

#endif