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

void	print_string(char *string, va_list args)
{
	int 	i;

	i = 0;
	va_end(args);
	while(string[i])
	{
		if (string[i] == '%' && string[i + 1] != '%')
		{
//			if ()
			i++;
		}
		else
			ft_putchar(string[i]);
		i++;
	}
}

int ft_printf(const char *string, ...)
{
    va_list args;
    va_list args_cpy;
    int     nbr_args;
    int     i;

    va_start(args_cpy, string);
    va_start(args, string);
	va_copy(args, args_cpy);
	nbr_args = get_nbr_args((char *)string);
	i = 0;
	while (i < nbr_args)
	{
		if (!va_arg(args_cpy, char *))
		{
			printf("nombre de parametre plus grand que le nombre de %%");
			return (0);
		}
		i++;
	}

	print_string((char *)string, args);
    va_end(args);
    va_end(args_cpy);
    return (0);
}

int main()
{
    ft_printf("t%srest%saa", "%zebi%", "asdf");
	//printf("%s", "zebi");
}