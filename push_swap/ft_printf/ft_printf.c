/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:15:43 by bmabilla      #+#    #+#             */
/*   Updated: 2023/11/01 12:15:45 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_format(va_list *args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		length += ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(*args, unsigned long), 87);
	else if (format == 'd' || format == 'i')
		length += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x')
		length += ft_print_hex(va_arg(*args, unsigned int), 87);
	else if (format == 'X')
		length += ft_print_hex(va_arg(*args, unsigned int), 55);
	else if (format == 'e')
	{
		ft_putstr_fd("Error\n", 2);
		length += 6;
	}
	else if (format == '%')
		length += ft_print_percent();
	return (length);
}

static	int	print_string(char *string, va_list *args)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			length += print_format(args, string[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(string[i]);
			length++;
		}
		i++;
	}
	return (length);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		length;

	va_start(args, string);
	length = print_string((char *)string, &args);
	va_end(args);
	return (length);
}
/*
int main()
{
    int test = ft_printf("%d%dd%d", 1, 2, -3);
	printf("\nreturn => %u", test);
}*/
