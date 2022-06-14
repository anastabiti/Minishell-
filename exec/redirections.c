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
	while (list[i].next != NULL)
	{
		// input = dup(0);
		// output = dup(1);
		if (list[i].redirection_out == 1)
		{
			list->fd_out = open(list[i].fileout, O_RDWR | O_CREAT | O_TRUNC,
					0600);
			if (list->fd_out == -1)
			{
				printf("bash: No such file or directory\n");
			}
		}
		if (list[i].redirection_in == 1)
		{
			list->fd_in = open(list[i].filein, O_RDONLY, 0);
			if (list->fd_in == -1)
			{
				printf("bash: No such file or directory\n");
			}
		}
		if(list[i].append_stdout  == 1)
		{
			list->fd_out = open(list[i].fileout, O_RDWR | O_CREAT | O_APPEND, 0600);	
		}
		i++;
	}
	return (0);
}