/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:13:35 by bmabilla      #+#    #+#             */
/*   Updated: 2023/11/20 16:13:37 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **sFirst, t_stack **sSecond)
{
	if (sSecond)
	{
		s_lstadd_front(sFirst, *sSecond);
		*sSecond = (*sSecond)->next;
	}
}

void	pa(t_stack **sA, t_stack **sB)
{
	ft_printf("pa\n");
	push(sA, sB);
}


void	pb(t_stack **sA, t_stack **sB)
{
	ft_printf("pb\n");
	push(sB, sA);
}