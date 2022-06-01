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

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	// struct s_builtins blt;
	struct s_list *list;
	char *input;
	list = (struct s_list *)malloc(sizeof(struct s_list));
	list->blt = (struct s_builtins *)malloc(sizeof(struct s_builtins) * 412);
	int fd = 1;
	list->environ = env;
	while (1)
	{

		list->input = ft_read(list->input);
		//

		ft_init(list);
		list[0].cmd[0] = "/bin/echo";
		list[0].cmd[1] = "-l";
		list[0].cmd[2] = NULL;
		list[0].next = &list[1];
		list[1].cmd[0] = "/usr/bin/wc";
		list[1].cmd[1] = NULL;

		///
		list[1].next = &list[2];

		list[2].cmd[0] = "/bin/echo";
		list[2].cmd[1] = "ANAS";
		list[2].cmd[2] = NULL;
		list[2].next = NULL;
		list->there_is_pipe = 0;
		list->cmd_nbr = 2;
		if (list->there_is_pipe == 0)
		{
			if (ft_is_built_in(list) == 0)
			{
				ft_bin_usr_sbin(list);
			}
		}
		if (list->there_is_pipe > 0)
		{

			ft_pipe(list);
		}
	}
	free(input);
}
