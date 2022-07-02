/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:10:47 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/02 11:39:33 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
  #include <stdio.h>
       #include <readline/readline.h>
       #include <readline/history.h>
# include "./exec/parse.h"
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <dirent.h> // open dir
# include <sys/wait.h>
# define TRUE 1
# define RDOUT "rstdout"
# define RDIN "rstdin"
# define RDAPPEND "rstdappend"
# define HEREDOC "HEREDOC"

/* ---------- START MACROS NEEDED IN PARSING ---------- */

# define PROMPT "minishell $ "
# define PRE_ERR "minishell: "
# define SNT_ERR "minishell: syntax error near unexpected token `"

/* ---------- END MACROS NEEDED IN PARSING ---------- */

// /* ---------- START TOKEN'S UTILS (MACROS STRUCT ENUM FUNCTIONS) ---------- */

// typedef enum e_token {
// 	S_QUOTE,
// 	D_QUOTE,
// 	IN_RED,
// 	IN_D_RED,
// 	OUT_RED,
// 	OUT_D_RED,
// 	PIPE,
// 	WORD
// }			t_e_token;

// typedef	struct s_token
// {
// 	char	*val;
// 	int		type;
// }			t_token;

void    ft_token(char *s);

/* ---------- END TOKEN'S UTILS (MACROS STRUCT ENUM FUNCTIONS) ---------- */

struct						s_list
{
	char					*cmd[50];
	struct s_list			*next;
	int						fd_out;
	char					*input;
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
	struct s_envp			*envp;

};

/* ------ START STRUCT FOR SPLIT ------ */

// typedef struct s_variables
// {
// 	int		l;
// 	int		i;
// 	int		j;
// 	int		cl;
// }			t_variables;

/* ------ END STRUCT FOR SPLIT ------ */

struct						s_envp
{
	char					**environment;
	int						envpitems;
	char **name;
	char **value;
	char **copy;
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
int							builtcheck_1(t_cmdl *cmd, struct s_envp *envp);
int							ftexit(t_cmdl *cmd, struct s_envp *envp);
int							builtcheck(t_cmdl *cmd, struct s_envp *envp);
int							ftcd(t_cmdl *cmd, struct s_envp *envp);
int							ft_export_1(struct s_envp *envp, t_cmdl *cmd);
int						ft_env(struct s_envp *envp, t_cmdl *list);
int							ft_echo(t_cmdl *list, int fd);
int							ft_is_built_in(t_cmdl *list, struct s_envp *envp);
int							ft_unset(struct s_envp *envp, t_cmdl *list,
								int arg);
int							ft_export(struct s_envp *envp, t_cmdl *cmd, int i);
//exece
int							is_builtin(t_cmdl *list, int i);
int							one_cmd(t_cmdl *list, struct s_envp *envp);
char						*ft_itoa(int n);
int	ft_split_env(struct s_envp *envp, char **env);
int							set_rd(struct s_list *list);
int							run_builtin(t_cmdl *list, struct s_envp *envp);
/// redirections I/O
int							redirections(t_cmdl *list);
int							heredoc_without_cmd(struct s_list *list);
// Other
t_list						*ft_lstnew(void *content);
int							ft_bin_usr_sbin(t_cmdl *list, struct s_envp *envp);
char						**ft_search_for_path(t_cmdl *list,
								struct s_envp *envp);
void						ftcheck_nopath(t_cmdl *list, struct s_envp *envp);
void						looping_through_split_path(t_cmdl *list, int i,
								char *bin, char *last, struct s_envp *envp);
char						**create_argv_for_execve(t_cmdl *list);
int							ft_check_programs(t_cmdl *list,
								struct s_envp *envp);
//env
int						ft_copy_1st_env(struct s_envp *envp, char **env);
// LIBFT
int							ft_isalpha(int c);
int							ft_isalnum(int c);
int							ft_isdigit(int c);
int							ft_atoi(const char *str);
char						*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack,
					const char *needle,
					size_t len);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char						*ft_strchr(const char *s, int c);
static char					*ccleaner(char **arr);
char    *ft_substr(char *s, unsigned int start, size_t len);
static size_t				countblocks(char const *s1, char delimiter);
char						**ft_split(char const *s, char c);
char						*ft_strdup(const char *s1);
void						*ft_memmove(void *s1, void *s2, size_t n);
size_t						ft_strlcpy(char *dst, const char *src,
								size_t dstsize);
void						*ft_memmove(void *s1, void *s2, size_t len);
size_t						ft_strlen(char const *s);
int							ft_search(char *s, char *c, int lenght);
// output libft
void						ft_putstr_fd(char *s, int fd);
void						ft_putchar_fd(char c, int fd);
void						ft_putendl_fd(char *s, int fd);
// read input
char						*ft_read(char *input);
// pipes
void						ft_pipe(t_cmdl *list, struct						s_envp * envp);
// signals
void						handler(int sig);
// init data
struct s_list				*ft_init(struct s_list *blt);
//export tools
char	**join_name_and_value(struct s_envp *envp, t_cmdl *cmd);
char	**ft_sort_env(struct s_envp *envp, t_cmdl *cmd);
int	ft_export_1(struct s_envp *envp, t_cmdl *cmd);
int	check_name_is_valid(char **split, int i, t_cmdl *cmd);
int	modify_name(struct s_envp *envp, t_cmdl *cmd, char **split, int i);
int	ft_equal_sign(struct s_envp *envp, t_cmdl *list, int arg);
//free
int free2d(char **s);
/* ---------- START LIBFT FUNCTIONS ---------- */

char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isspace(int c);
int		ft_strcmp(const char *s1, const char *s2);

/* ---------- END LIBFT FUNCTIONS ---------- */

/* ---------- START LINKED LIST FUNCTIONS ---------- */

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/* ---------- END LINKED LIST FUNCTIONS ---------- */
#endif
