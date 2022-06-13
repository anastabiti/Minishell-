/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:50:59 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/21 09:51:00 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int redirections(struct s_list *list)
{
    int i = 0;
    while(list[i].next != NULL)
    {
        if (list[i].REDIRECTION_OUT == 1)
			{
				// dup2(list->fd_out, 1);
				// i should use a while loop ; while there is an 
				list->fd_out = open(list[i].fileout, O_RDWR | O_CREAT | O_TRUNC,
									0600);
		if(list->fd_out == -1)
				{
					printf("bash: No such file or directory\n");
				}
			}
			 if (list[i].REDIRECTION_IN == 1)
			{
				// dup2(list->fd_in, 0);
				list->fd_in = open(list[i].filein, O_RDONLY, 0);
				if(list->fd_in == -1)
				{
					printf("bash: No such file or directory\n");
				}
                		// close(list->fd_in);

			}
            i++;
    }
    printf("%d\n", i);
    return 0;
}