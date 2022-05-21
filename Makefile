# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 07:58:53 by atabiti           #+#    #+#              #
#    Updated: 2022/05/21 09:12:54 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC =   ./exec/builtins.c  ./execft_env.c    ./execmain.c ./exectools.c
OBJ =  ./exec/builtins.o  ./exec/ft_env.o    ./exec/main.o   ./exec/tools.o   
FALGS = -Wall -Werorr -Wextra 
all : $(NAME)

$(NAME) : $(OBJ)
	cc  $(FLAGS)  $(OBJ)  -o $(NAME) -lreadline -L/goinfre/atabiti/.brew/opt/readline/lib -I/goinfre/atabiti/.brew/opt/readline/include -Iminishell.h 
clean :
		cd ./exec; \
	rm *.o
	
fclean : clean
	rm $(NAME)
re : fclean all