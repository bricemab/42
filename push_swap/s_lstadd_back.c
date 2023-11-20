/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lstadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:49:12 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/25 14:49:13 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*l;

	if (lst)
	{
		if (*lst)
		{
			l = s_lstlast(*lst);
			l->next = new;
		}
		else
			*lst = new;
	}
}
