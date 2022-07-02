/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:32:15 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/02 09:27:19 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_read(char *input)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
	input = readline("MINISHELL-BETA $ "); // like getnextline : readline will read a line from the terminal and return it,
	// size_t llenght = ft_strlen(input);
	if (!input) // ctrl-D
	{
		write(2, "exit\n", 5);
		rl_clear_history();
			
		free(input);
		exit(1);
	}
	add_history(input); // to save commandes history >> you can access it by up arrow ^.

	return input;
}

void handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();				//  Tell the update functions that we have moved onto a new (empty) line
		rl_replace_line("", 0); // needs to include the LIB and /include dir to work
		rl_redisplay();					// Change what's displayed on the screen to reflect the current contents of rl_line_buffer.

	}
	
}