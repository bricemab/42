/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:13:53 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/20 16:14:03 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_stack **stack)
{
	ft_printf("sa\n");
	swap(stack);
}

void	swap_b(t_stack **stack)
{
	ft_printf("sb\n");
	swap(stack);
}

void	swap_s(t_stack **sA, t_stack **sB)
{
	swap_a(sA);
	swap_a(sB);
}
