/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:58:51 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/20 12:58:55 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_int(char **args, int nb)
{
	int		i;
	long	curr;

	i = 1;
	while (i < nb)
	{
		curr = ft_atoi(args[i]);
		if (!curr)
			exit_error("only_int => not numeric");
		if (curr > INT_MAX || curr < INT_MIN)
			exit_error("only_int => is numeric but not int");
		i++;
	}
}

void	exist_in_array(int nbr, char **args, int nb)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_atoi(args[i]) == nbr && i != nb)
			exit_error("exist_in_array => already exist in argv");
		i++;
	}
}

void	check_args(char	**args, int nb)
{
	int	i;

	if (nb < 2)
		exit_error("check_args => missing arguments");
	i = 1;
	only_int(args, nb);
	while (i < nb)
	{
		exist_in_array(ft_atoi(args[i]), args, i);
		i++;
	}
}
