/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:40 by bmabilla      #+#    #+#             */
/*   Updated: 2023/11/01 12:14:51 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*create_string(unsigned int value, int *strlen)
{
	int				i;
	unsigned int	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	ft_print_hex(unsigned int value, int asc)
{
	char			*string;
	int				*ptr;
	int				i;
	unsigned int	tmp;

	ptr = &i;
	tmp = value;
	string = create_string(value, ptr);
	if (!string)
		return (0);
	while (tmp != 0)
	{
		if ((tmp % 16) < 10)
			string[i] = (tmp % 16) + 48;
		else
			string[i] = (tmp % 16) + asc;
		tmp = tmp / 16;
		i--;
	}
	ft_putstr(string);
	i = ft_strlen(string);
	free(string);
	if (value == 0)
		i += ft_print_char('0');
	return (i);
}
