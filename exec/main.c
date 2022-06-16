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
		// cmd 1
		list[0].cmd[0] = "pwd";

		list[0].type[0] = RDOUT;
		list[0].file[0] = "ff";

		list[0].type[1] = RDOUT;
		list[0].file[1] = "f1";

		list[0].type[2] = RDOUT;
		list[0].file[2] = "f2";

		list[0].type[3] = RDOUT;
		list[0].file[3] = "f3";
		list[0].type[4] = NULL;

		////
			list[1].cmd[0] = "pwd";

		list[1].type[0] = RDOUT;
		list[1].file[0] = "f1f";

		list[1].type[1] = RDOUT;
		list[1].file[1] = "f21";

		list[1].type[2] = RDOUT;
		list[1].file[2] = "f22";

		list[1].type[3] = RDOUT;
		list[1].file[3] = "f113";
		list[1].type[4] = NULL;

		///..................................
		list->cmd_nbr = 2;
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