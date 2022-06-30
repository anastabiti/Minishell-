/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:58:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/25 10:42:21 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_num_cmd(t_data *data)
{
	int	i;
	int	quotes[2];
	int	num_cmd;

	i = -1;
	num_cmd = 1;
	quotes[0] = 1;
	quotes[1] = 1;
	while (data->cmd_line[++i])
	{
		if (data->cmd_line[i] == '\"' && quotes[1] == 1)
			quotes[0] *= -1;
		else if (data->cmd_line[i] == '\'' && quotes[0] == 1)
			quotes[1] *= -1;
		if (quotes[1] + quotes[0] == 2)
			if (data->cmd_line[i] == '|')
				num_cmd++;
	}
	return (num_cmd);
}

int	get_min_cmd(t_data *data)
{
	int	i;
	int	quotes[2];
	int	index;
	int	j;

	i = -1;
	j = 0;
	quotes[0] = 1;
	quotes[1] = 1;
	index = 0;
	data->num_cmd = get_num_cmd(data);
	return (0);
}

void	prep_token(t_data *data)
{
	if (!get_min_cmd(data))
		return ;
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*line;
	t_cmdl	*cmd;

	if (argc == 1)
	{
		while (1)
		{
			data.cmd_line = readline(PROMPT);
			if (!data.cmd_line)
			{
			}
			if (ft_strlen(data.cmd_line))
			{
				add_history(data.cmd_line);
				prep_token(&data);
			}
		}
	}
}
