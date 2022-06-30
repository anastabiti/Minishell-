/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:50:22 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/28 10:17:55 by atabiti          ###   ########.fr       */
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

int	ft_env(struct s_envp *envp, t_cmdl *list)
{
	int	i;

	// t_list	*new = malloc(sizeof(t_list	*));
	// 	new =  ft_lstnew(envp->environment);
	i = 0;
	// while (i < envp->envpitems)
	// {
	// 	new->content = *envp->environment;
	// 	ft_putendl_fd(new->content, list->fd_out);
	// 	envp->environment++;
	// 	i++;
	// }
	while (i < envp->envpitems)
	{
		ft_putendl_fd(envp->environment[i], 1);
		i++;
	}
	return (0);
}
