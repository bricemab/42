/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:17:40 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/05 17:08:58 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_printnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		len += ft_printchar('-');
		len += ft_printchar('2');
		len += ft_printnbr(147483648);
	}
	else if (nbr >= 0 && nbr < 10)
	{
		len += ft_printchar(nbr + 48);
	}
	else if (nbr < 0)
	{
		len += ft_printchar('-');
		len += ft_printnbr(nbr * -1);
	}
	else
	{
		len += ft_printnbr(nbr / 10);
		len += ft_printchar(nbr % 10 + 48);
	}
	return (len);
}
