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

#include "../minishell.h"
// ping is /sbin/ping
/*
testtin with bash-3.2$ 
pwd >> f1 > f2 >  f3  write in f3 only
*/

int	main(int ac, char **av, char **env)
{
	struct s_list *list;
	char *input;
	int fd;
	char *upstream[20], *downstream[20];
	int i;

	(void)ac;
	(void)av;
	list = (struct s_list *)malloc(sizeof(struct s_list) * 1);
	list->blt = (struct s_builtins *)malloc(sizeof(struct s_builtins) * 42);
	list->rd = (struct s_redirections *)malloc(sizeof(struct s_redirections)
			* 42);
	fd = 1;
	list->environ = env;
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		list->input = ft_read(list->input);
		ft_init(list);
		//......... cmds with args and options
		// cmd 1
		list[0].cmd[0] = "pwd";

		list[0].rd[0].type = RDOUT;
		list[0].rd[0].file = "ff";

		list[0].rd[1].type = RDOUT;
		list[0].rd[1].file = "f1";

		list[0].rd[2].type = RDOUT;
		list[0].rd[2].file = "f2";

		list[0].rd[3].type = RDOUT;
		list[0].rd[3].file = "f3";

		// list[0].rd[4].type = NULL;
		list[0].next = &list[1];
		/// command 2
		list[1].cmd[0] = "pwd";

		list[1].rd[6].type = RDOUT;
		// list[1].rd[0].file = "g1";

		// list[1].rd[1].type = RDOUT;
		// list[1].rd[1].file = "g2";

		// list[1].rd[2].type = RDOUT;
		// list[1].rd[2].file = "g3";

		// list[1].rd[3].type = RDOUT;
		// list[1].rd[3].file = "g4";

		// // list[1].rd[4].type = NULL;
		// list[1].next = &list[2];
		// // list[2].next = NULL;

		///..................................
		list->cmd_nbr = 1;
		list->cmd_iteration = 0;

		if (one_cmd(list) == 0)
		{
			if (list->cmd_nbr > 1)
			{
				ft_pipe(list);
			}
		}
	}
	free(input);
}