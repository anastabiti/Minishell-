/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:14:58 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/20 07:28:27 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int here_doc(struct s_list *list)
{
    int  i = 0;
    while(i < list->cmd_nbr)
    {

        if(ft_strncmp(HEREDOC , list[i].type[i], 7) == 0)
        { char *line;
            while(1)
            {
                signal(SIGINT, handler);
                signal(SIGQUIT, SIG_IGN);
                
              
                if(fork() == 0)
                {
                    int fd = open("HEREDOCTMP", O_RDWR, 0600);
                    line = readline(">");
                      if(ft_strncmp(line , list[i].delimiter[i], 3) == 0)
                {
                    break;
                }
                write(fd, line, ft_strlen(line));
                write(fd, "\n", 1);
                }
                else
                {
                    wait(NULL);
                }
            }
        }
     i++;   
    }
 return 0;   
}