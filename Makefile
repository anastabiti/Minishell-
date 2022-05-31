# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 07:58:53 by atabiti           #+#    #+#              #
#    Updated: 2022/05/31 09:31:24 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC =   ./exec/builtins.c  ./exec/ft_env.c \
 ./exec/main.c ./exec/tools.c  redirections.c   \
 ./libft/ft_strnstr.c   ./exec/ft_unset.c ./exec/ft_export.c \
  ./exec/ft_others.c   ./exec/ft_readline.c  ./exec/ft_init.c ./libft/ft_putchar_fd.c \
./libft/ft_putstr_fd.c           ./libft/ft_putendl_fd.c  ./exec/ftpipe.c \

OBJ =  ./exec/builtins.o  ./exec/ft_env.o    ./exec/main.o  \
 ./exec/tools.o      ./exec/redirections.o  ./libft/ft_strnstr.o  \
 ./exec/ft_unset.o ./exec/ft_export.o ./exec/ft_others.o \
  ./exec/ft_readline.o ./exec/ft_init.o  ./libft/ft_putchar_fd.o \
./libft/ft_putstr_fd.o           ./libft/ft_putendl_fd.o  ./exec/ftpipe.o \
	
FALGS = -Wall -Werorr -Wextra 
all : $(NAME)

$(NAME) : $(OBJ)
	clang -g $(FLAGS)  $(OBJ)  -o $(NAME) -lreadline -L/Users/atabiti/.brew/Cellar/readline/8.1.2/lib -I/Users/atabiti/.brew/Cellar/readline/8.1.2/include
	gcc builtins_bin/ft_echo.c -o builtins_bin/ftecho
	gcc builtins_bin/ft_cd.c -o builtins_bin/ft_cd

	
clean :
		cd ./exec; \
	rm *.o
		cd ./libft; \
			rm *.o
		cd ./builtins_bin; \
	rm ftecho ft_cd
fclean : clean
	rm $(NAME)
re : fclean all