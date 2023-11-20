/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:56:31 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/20 12:56:33 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stackA(t_stack **sA, char **args, int nb)
{
	int		i;
	t_stack	*new;

	(*sA) = malloc(sizeof(t_stack));
	if (!(*sA))
		exit_error("init_stacks => error while allocate memory");
	i = 2;
	(*sA)->value = ft_atoi(args[1]);
	(*sA)->pos = 0;
	(*sA)->next = NULL;
	while (i < nb)
	{
		new = s_lstnew(ft_atoi(args[i]), i - 1);
		if (!new)
			exit_error("init_stacks => error while allocate memory new stack");
		s_lstadd_back(sA, new);
		i++;
	}
}

void	complexe_sort()
{

}

int	basic_check(t_stack **stack, int nb)
{
	if (!(*stack)->next)
		exit(EXIT_SUCCESS);
	if (nb == 3) // stack de 2
		if ((*stack)->value > (*stack)->next->value)
			swap_a(stack);
	if (nb == 4) // stack de 3
	{
		if ((*stack)->value > (*stack)->next->value)
			swap_a(stack);
		if ((*stack)->value > (*stack)->next->next->value)
			rra(stack);
		if ((*stack)->next->value > (*stack)->next->next->value)
		{
			swap_a(stack);
			rra(stack);
			rra(stack);
		}
	}
	if (nb > 4)
		complexe_sort();
	return (0);
}

int	main(int nb, char **args)
{
	t_stack	*sA;
	//t_stack	*sB;

	if (nb == 1)
		return (1);
	check_args(args, nb);
	init_stackA(&sA, args, nb);
	basic_check(&sA, nb);
	//printf("%d  %d  %d\n", (sA)->value, (sA)->next->value, ((sA)->next)->next->value);
}
