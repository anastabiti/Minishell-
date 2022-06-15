/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:50:59 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/14 11:43:40 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirections(struct s_list *list)
{
	int i = 0;
	int input;
	int output;
	while (list[0].rd[i].type != NULL)
	{
		// input = dup(0);
		// output = dup(1);
		if (ft_strncmp(list[0].rd[i].type , RDOUT, 7) == 0)
		{
			list->fd_out = open(list[0].rd[i].file, O_RDWR | O_CREAT | O_TRUNC,
					0600);
			if (list->fd_out == -1)
			{
				printf("bash: No such file or directory\n");
			}
		}
		if (ft_strncmp(list[0].rd[i].type , RDIN, 6) == 0)
		{	
			list->fd_in = open(list[0].rd[i].file, O_RDONLY, 0);
			if (list->fd_in == -1)
			{
				printf("bash: No such file or directory\n");
			}
		}
		if (ft_strncmp(list[0].rd[i].type , RDAPPEND, 10) == 0)
		{
			list->fd_out = open(list[0].rd[0].file, O_RDWR | O_CREAT | O_APPEND, 0600);	
		}
		i++;
	}
	return (0);
}