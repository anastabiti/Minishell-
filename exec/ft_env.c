/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:50:22 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/25 18:52:18 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_env(struct						s_envp * envp, t_cmdl *list)
{
	// t_list	*new = malloc(sizeof(t_list	*));
	// 	new =  ft_lstnew(envp->environment);
	int  i = 0;
	// while (i < envp->envpitems)
	// {
	// 	new->content = *envp->environment;

	// 	ft_putendl_fd(new->content, list->fd_out);
	// 	envp->environment++;
	// 	i++;
	// }
	while (i < envp->envpitems)
	{
		ft_putendl_fd(envp->environment[i], list->fd_out);
		i++;
	}
}
