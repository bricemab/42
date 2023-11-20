/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lstnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:49:58 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/25 14:49:59 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*s_lstnew(int content, int pos)
{
	t_stack	*c;

	c = malloc(sizeof(t_stack));
	if (!c)
		return (NULL);
	c->value = content;
	c->pos = pos;
	c->next = NULL;
	return (c);
}
