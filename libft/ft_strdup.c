/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:06:34 by atabiti           #+#    #+#             */
/*   Updated: 2022/06/01 13:03:33 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1)
{
	size_t	lenght;
	char	*copyptr;

	lenght = ft_strlen(s1) + 1;
	copyptr = malloc(lenght);
	if (copyptr == NULL)
		return (NULL);
	ft_memcpy(copyptr, s1, lenght);
	return (copyptr);
}
