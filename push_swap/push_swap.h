/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:00:47 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/20 13:00:48 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "limits.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	struct s_stack	*next;
}	t_stack;

void	exit_error(char *fn);
void	check_args(char	**args, int nb);

t_stack	*s_lstlast(t_stack *lst);
t_stack	*s_lstnew(int content, int pos);
void	s_lstadd_back(t_stack **lst, t_stack *new);

void	rra(t_stack **stack);

void	ra(t_stack **stack);
void	rb(t_stack **stack);

void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap_s(t_stack **sA, t_stack **sB);

#endif