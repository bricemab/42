/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:49:58 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/25 14:49:59 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = malloc(sizeof(t_list));
	if (!c)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}
