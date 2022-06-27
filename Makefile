# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 07:58:53 by atabiti           #+#    #+#              #
#    Updated: 2022/06/26 11:39:24 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = ./exec/builtins.c \
	./exec/ft_env.c \
	./exec/tools.c \
	./exec/redirections.c \
	./libft/ft_strnstr.c \
	./exec/ft_unset.c \
	./exec/ft_export.c \
	./exec/ft_others.c \
	./exec/ft_readline.c \
	./exec/ft_init.c  \
	./libft/ft_putchar_fd.c \
	./libft/ft_putstr_fd.c \
	./libft/ft_putendl_fd.c \
	./exec/ftpipe.c \
	./exec//libft.c \
	./exec/ft_one_command.c \
	./exec/ft_multi_cmds.c   \
	./libft/ft_strdup.c  \
	./exec/ft_here_doc.c \
	./exec/ft_split.c \
	./exec/parse.c \
	./exec/utils.c \
	./exec/ft_search_path.c \
	./exec/is_builtin.c \
	./exec/ft_exit.c \
	./exec/ftcd.c \
	./exec/ft_copy_1st_env.c \

OBJ = ./exec/builtins.o \
	./exec/ft_env.o \
	./exec/tools.o \
	./exec/redirections.o \
	./libft/ft_strnstr.o  \
	./exec/ft_unset.o \
	./exec/ft_export.o \
	./exec/ft_others.o \
	./exec/ft_readline.o \
	./exec/ft_init.o \
	./libft/ft_putchar_fd.o \
	./libft/ft_putstr_fd.o \
	./libft/ft_putendl_fd.o \
	./exec/ftpipe.o \
	./exec/libft.o \
	./exec/ft_one_command.o \
	./exec/ft_multi_cmds.o \
	./exec/ft_split.o \
	./exec/ft_here_doc.o \
	./exec/parse.o \
	./exec/utils.o \
	./exec/ft_search_path.o \
	./exec/is_builtin.o \
	./exec/ft_exit.o \
	./exec/ftcd.o \
	./exec/ft_copy_1st_env.o \

FALGS = -Wall -Werorr -Wextra 
all : $(NAME)

$(NAME) : $(OBJ)
	gcc -g $(FLAGS)  $(OBJ)  -o $(NAME) -lreadline -L /Users/$(USER)/goinfre/.brew/opt/readline/lib -I /Users/$(USER)/goinfre/.brew/opt/readline/include
		gcc builtins_bin/ft_echo.c ./libft/ft_putchar_fd.c  ./libft/ft_putendl_fd.c ./exec/tools.c    ./libft/ft_strnstr.c -o builtins_bin/ftecho 
		gcc builtins_bin/ft_cd.c  ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c  ./exec/tools.c   ./libft/ft_strnstr.c -o builtins_bin/ftcd 
		gcc builtins_bin/ft_pwd.c ./libft/ft_putchar_fd.c  ./libft/ft_putendl_fd.c ./exec/tools.c   ./libft/ft_strnstr.c -o builtins_bin/ftpwd 
		gcc builtins_bin/ft_unset.c ./libft/ft_putchar_fd.c  ./libft/ft_putendl_fd.c  ./exec/tools.c   ./libft/ft_strnstr.c -o builtins_bin/ftunset 
		gcc builtins_bin/ft_env.c  ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./exec/tools.c ./libft/ft_strnstr.c -o builtins_bin/ftenv 
		gcc builtins_bin/ft_export.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c  ./exec/tools.c   ./libft/ft_strnstr.c -o builtins_bin/ftexport
			gcc builtins_bin/ft_exit.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./exec/tools.c  ./libft/ft_strnstr.c -o builtins_bin/ftexit
	
clean :
		cd ./exec; \
	rm *.o
		cd ./libft; \
			rm *.o
		cd ./builtins_bin; \
	rm ftecho  ftcd  ftpwd ftunset  ftenv ftexport ftexit       
	
fclean : clean
	rm $(NAME)
re : fclean all
