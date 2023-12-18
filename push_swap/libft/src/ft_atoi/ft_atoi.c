/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:20:55 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/09 12:20:59 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/***
 *	Transforme une string en int
 */

int	ft_atoi(const char *str)
{
	int	i;
	int	toint;
	int	isneg;

	i = 0;
	toint = 0;
	isneg = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isneg = -isneg;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		toint = (toint * 10) + (str[i] - '0');
		i++;
	}
	return (isneg * toint);
}
