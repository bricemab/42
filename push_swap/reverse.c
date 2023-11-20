/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:13:42 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/20 16:13:43 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack)
{
	t_stack *last;
	t_stack *before_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	ft_printf("rra\n");
	last = *stack;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}

	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}