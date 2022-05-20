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

// #include <sys/wait.h>
// void hand(int sig, siginfo_t *info, void *other)
// {
// 	if (sig == SIGINT)
// 	{
// 		write(1, " sig\n", 4);
// 		// kill();
// 	}
// 	if (sig == SIGQUIT)
// 		{
// 			write(1, " sig\n", 4);
// 		}
// }
void handler(int sig)
{
	if (sig == SIGINT)
	{
		// kill();
		write(1, "\b\b", 2); // move cursor behind of ^C
		write(1, "  ", 2);	 // remove ^C by printing spaces.
		write(1, "\b\b", 2); // reset cursor pos
	}
	if (sig == SIGQUIT)
	{
		write(1, "\b\b", 2); // move cursor behind of ^C
		write(1, "  ", 2);	 // remove ^C by printing spaces.
		write(1, "\b\b", 2); // reset cursor pos
	}
}
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	while (1)
	{

		// struct sigaction sa;
		// sa.sa_sigaction = &hand;
		// sa.sa_flags = SA_SIGINFO;

		// sigaction(SIGINT, &sa, NULL);
		// sigaction(SIGQUIT, &sa, NULL);

		signal(SIGINT, handler);
		signal(SIGQUIT, handler);

		struct s_builtins blt;

		char *input = readline("MINI_SHELl >>>>> $ "); // like getnextline : readline will read a line from the terminal and return it,
		if (!input)
			break;
		blt.echo = "echo";
		blt.cd = "cd";
		blt.pwd = "pwd";
		blt.export = "export";
		blt.unset = "unset";
		blt.env = "env";
		blt.exit = "exit";
		blt.cd_path = "/Users/atabiti/Desktop/";
		// char **vr = env;
		add_history(input); // to save commandes history >> you can access it by up arrow ^.
		ft_is_built_in(blt, input, env);
	}
}
