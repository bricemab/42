/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lstadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:49:12 by bmabilla      #+#    #+#             */
/*   Updated: 2023/10/25 14:49:13 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

