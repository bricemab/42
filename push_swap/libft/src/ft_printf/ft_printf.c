/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:45:00 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 13:42:46 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_search(va_list args, const char c)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_len += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		print_len += ft_print_char('%');
	else if (c == 'e')
		print_len += ft_print_stderr(va_arg(args, char *));
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += ft_search(args, str[i + 1]);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			len += ft_print_char(str[i]);
			if (len == -1)
				return (-1);
		}
	}
	va_end(args);
	return (len);
}
