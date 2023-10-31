#include "ft_printf.h"

int	get_nbr_args(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i+1] != '%')
		{
			count++;
			i++;
		}
		i++;
	}
	return count;
}

int	print_format(va_list *args, const char format)
{
	int length;

	length = 0;
	if (format == 'c')
		length += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		length += ft_print_str(va_arg(*args, char *));
//	else if (format == 'p')
//		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(*args, unsigned int));
//	else if (format == 'x' || format == 'X')
//		length += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		length += ft_print_percent();
	return (length);
}

int	print_string(char *string, va_list *args)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while(string[i])
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

int ft_printf(const char *string, ...)
{
    va_list args;
    va_list args_cpy;
    int     length;

    va_start(args_cpy, string);
    va_start(args, string);
	length = print_string((char *)string, &args);
    va_end(args);
    va_end(args_cpy);
    return (length);
}

int main()
{
    int test = ft_printf("%s%s%u = %d", "Hello ", "World !", 100, 100);
	printf("\nreturn => %u", test);
}