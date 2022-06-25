/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/24 22:20:50 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse.h"
#include "../minishell.h"

int	main(int argc, char **argv,  char **env)
{
	char	*line;
	t_cmdl	*cmd;
	int		start;
	int		i;
	int		pipe = 1;
	

	if (argc == 1)
	{
		while (1)
		{
			signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
			pipe = 1;
			line = readline(PROMPT);
			//mine
				if (!line) // ctrl-D
	{
		write(2, "exit\n", 5);
		rl_clear_history();

		free(line);
		exit(1);
	}
//
			add_history(line);
			// if (!check_err_pipe(line) || !check_valid(line))
			// 	continue;
			i = -1;
			while (line[++i])
				if (line[i] == '|')
					pipe++;
			cmd = (t_cmdl *)malloc(sizeof(t_cmdl) * (pipe));
			if (!cmd)
				return (0);
			i = -1;
			start = 0;
			int j = 0;
			while (j < pipe)
			{
				cmd[j].cmd = NULL;
				cmd[j].args = NULL;
				cmd[j].in_red = NULL;
				cmd[j].out_red = NULL;
				while (line[++i])
				{
					if (line[i] != ' ' && (line[i] < 9 || line[i] > 13))
						break;
				}
				while (line[++i])
				{
					if (line[i] == ' ' || !line[i + 1])
					{
						cmd[j].cmd = ft_substr(line, start, i - start + !line[i + 1]);
						start = i + 1;
						break;
					}
				}
				while (line[++i])
				{
					if (line[i] == '|' || line[i] == '<' || line[i] == '>' || !line[i + 1])
					{
						cmd[j].args = ft_substr(line, start, i - start + !line[i + 1]);
						start = i + 1;
						break;
					}
				}
				if (line[i - 1] == '>' || line[i] == '>')
				{
					while (line[++i])
					{
						if (line[i] == '|' || !line[i + 1])
						{
							cmd[j].out_red = ft_substr(line, start, i - start + !line[i + 1]);
							start = i + 1;
							break;
						}
					}
				}
				if (line[i - 1] == '<' || line[i] == '<')
				{
					while (line[++i])
					{
						if (line[i] == '|' || !line[i + 1])
						{
							cmd[j].in_red = ft_substr(line, start, i - start + !line[i + 1]);
							start = i + 1;
							break;
						}
					}
				}
				j++;
			}
			i = 0;
			j = 0;
			while (i < pipe)
			{
	
				// printf("%d -- %s -- %s -- %s -- %s\n", i , cmd[i].cmd, cmd[i].args, cmd[i].in_red, cmd[i].out_red);
				i++;
			}
			 cmd->cmd_nbr = 0;
			 cmd->environ = env;
			 cmd->cmd_iteration = 0;
			if( cmd->cmd_nbr == 0)
			{
				// heredoc_without_cmd(cmd);
	
			one_cmd(cmd);
		}
			}
			
	}
	return 0;
}
