/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:13:49 by bmabilla      #+#    #+#             */
/*   Updated: 2023/11/20 16:13:50 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	first = *stack;
	last = s_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **stack)
{
	ft_printf("ra\n");
	rotate(stack);
}

void	rb(t_stack **stack)
{
	ft_printf("rb\n");
	rotate(stack);
}