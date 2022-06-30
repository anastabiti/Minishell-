/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:39:49 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/18 10:40:11 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minishell.h"

// ping is /sbin/ping
/*
testtin with bash-3.2$ 
pwd >> f1 > f2 >  f3  write in f3 only
*/
/*
///......
wc test.txt | ps > s >>>>> problem here it prints in stdout 
cat > fruits.txt << EOF  it create a file with the input from here doc

cat << EOF > a Instead of displaying the output on the screen you can redirect it to a file using the >,
	>> operators.
	cd ../../etc/ not working
	cat < Makefile | wc not working  ??? working  by removing
		&& redire_2(list) == 0 
	ps > test.txt | wc  is not working by removing
		&& redire_2(list) == 0  but working by adding  && redire_2(list) == 0
	ls | wc is not working after fixing the last bug

//////...  
*/
int	main(int ac, char **av, char **env)
{
	struct s_list *list;
	char *input;
	int fd;
	char *upstream[20], *downstream[20];
	int i;
	i = 0;
	(void)ac;
	(void)av;
	list = (struct s_list *)malloc(sizeof(struct s_list) * 2);
	list->blt = (struct s_builtins *)malloc(sizeof(struct s_builtins) * 2);
	// list->rd = (struct s_redirections *)malloc(sizeof(struct s_redirections)
	// 		* 2);
	fd = 1;
	list->environ = env;
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		list->input = ft_read(list->input);
		ft_init(list);
		//......... cmds with args and options
		// test 1
		// list[0].cmd[0] = "ls";
		// list[0].type[0] = RDOUT;
		// list[0].file[0] = "APPENDIT";
		// list[0].delimiter[0] = "EOF";
		// list[0].type[1] = NULL;
		// list[1].cmd[0] = "wc";
		// list[1].type[0] = NULL;
		// list[1].file[0] = "11";

		///..................................
		//test 2
		//ls | wc | wc is not working
		list[0].cmd[0] = "./a.out";
		list[0].cmd[1] = NULL;

		list[0].type[0] = NULL;
		// list[0].file[0] = "file1";
		// list[0].delimiter[0] = "EOF";
		// list[0].type[1] = RDOUT;
		// list[0].file[1] = "file3";
		// list[0].type[2] = HEREDOC;
		// list[0].type[3] = NULL;

		list[1].cmd[0] = "wc";
		list[1].type[0] = NULL;
		list[1].file[0] = "f2";

		list[1].type[1] = NULL;

		list[2].cmd[0] = "wc";
		list[2].type[0] = NULL;
		list[2].file[0] = "test.txt";
		//.....

		// list->cmd_nbr = 1;
		// list->cmd_iteration = 0;
		// list->there_is_pipe = 0;

		heredoc_without_cmd(list);
		if (list->cmd_nbr == 1)
		{
			one_cmd(list);
		}

		if (list->cmd_nbr > 1)
		{
			ft_pipe(list);
		}
	}

	free(input);
	return (0);
}