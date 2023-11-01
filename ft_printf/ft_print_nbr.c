/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:15:00 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/01 12:15:02 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_print_nbr(int c)
{
	int	length;
	int	nbr;

	nbr = c;
	length = 0;
	if (nbr < 0)
		length++;
	if (nbr == 0)
	{
		ft_putnbr(c);
		return (1);
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		length++;
	}
	ft_putnbr(c);
	return (length);
}
