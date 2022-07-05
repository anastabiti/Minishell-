/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/02 17:42:08 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../minishell.h"
/* 
cases
declare -x asdf="\\n\\\"s\"df\""
declare -x sdf="s\"df\"echo"
bash-3.2$ export asdf='\n\"s"df"'
/Users/atabiti/goinfre/.brew/bin/valgrind
*/
int main(int argc, char **argv, char **env)
{
	char *line;
	t_cmdl *cmd;

	int start;
	int i;
	int pipe = 1;
	struct						s_envp * envp;
	envp = (struct	s_envp *)malloc((1) * sizeof(	struct	s_envp));
 ft_copy_1st_env(envp, env);
		
		while (1)
		{
			signal(SIGQUIT, SIG_IGN);
			signal(SIGINT, handler);
			pipe = 1;
			line = readline(PROMPT);
			add_history(line);
			if (!check_err_pipe(line) || !check_valid(line))
				continue;
			i = -1;
			while (line[++i])
				if (line[i] == '|')
					pipe++;
			cmd = (t_cmdl *)malloc(sizeof(t_cmdl) * (pipe));
					cmd->fd_out = 1;

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
				i++;
				while (line[i])
				{
					if (line[i] != ' ' && (line[i] < 9 || line[i] > 13))
						break;
					i++;
				}
				while (line[i])
				{
					if (line[i] == ' ' || !line[i + 1])
					{
						cmd[j].cmd = rm_spaces(ft_substr(line, start, i - start + !line[i + 1]));
						start = i + 1;
						break;
					}
					i++;
				}
				while (line[i])
				{
					if (line[i] == '|' || line[i] == '<' || line[i] == '>' || !line[i + 1])
					{
						cmd[j].args = ft_split(rm_spaces(ft_substr(line, start, i - start + !line[i + 1])), ' ');
						start = i + 1;
						break;
					}
					i++;
				}
				if (line[i - 1] == '>' || line[i] == '>')
				{
					while (line[i])
					{
						if (line[i] == '|' || !line[i + 1])
						{
							cmd[j].out_red = rm_spaces(ft_substr(line, start, i - start + !line[i + 1]));
							start = i + 1;
							break;
						}
						i++;
					}
				}
				if (line[i - 1] == '<' || line[i] == '<')
				{
					while (line[i])
					{
						if (line[i] == '|' || !line[i + 1])
						{
							cmd[j].in_red = rm_spaces(ft_substr(line, start, i - start + !line[i + 1]));
							start = i + 1;
							break;
						}
						i++;
					}
				}
				j++;
			}
						cmd->cmd_nbr = pipe;
							cmd->there_is_pipe = pipe - 1;
			i = 0;
			j = 0;
			
			// while(cmd[i].cmd)
			// {
			// 	printf("pipe is %d \n", pipe - 1);
			// 					printf("cmd nbr is %d \n", cmd->cmd_nbr );

			// 	if(cmd[i].args[j] == NULL)
			// 	{
			// 								printf("%d cmd %s\n", i , cmd[i].cmd);

			// 	}
			// 		while(cmd[i].args[j])
			// 		{
			// 			printf("%d cmd %s args = %s\n", i , cmd[i].cmd, cmd[i].args[j]);
			// 			j++;
			// 		}
			// 		if(cmd[i].in_red)
			// 		{
			// 				printf("%d rdin %s\n", i , cmd[i].in_red);
			// 		}
			// i++;
			// }
	
			cmd->cmd_iteration = 0;
			if (cmd->cmd_nbr == 1 && cmd[0].cmd != NULL)
			{
				// heredoc_without_cmd(cmd);

				one_cmd(cmd, envp);
			}
			else if(cmd->cmd_nbr > 1)
			{
				//problem wc  | ls ? in bash ls is printing first and problem in  wc | ls when unset the PATH it must shot 2 errors not one
				// grep 1337 exec/*.c problem
				ft_pipe(cmd, envp);
			}
		// }
		free(line);
	}
	return 0;
}
