#include "ft_printf.h"

static	char	*create_string(unsigned long v, int *strlen)
{
	char			*str;
	int				i;

	i = 0;
	while (v != 0)
	{
		v = v / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	ft_print_ptr(unsigned long value, int asc)
{
	unsigned long	tmp;
	char			*string;
	int				i;
	int				*ptr;

	ptr = &i;
	tmp = value;
	string = create_string(value, ptr);
	if (!string)
		return (0);
	while (tmp != 0 && i-- >= 0)
	{
		if ((tmp % 16) < 10)
			string[i + 1] = (tmp % 16) + 48;
		else
			string[i + 1] = (tmp % 16) + asc;
		tmp = tmp / 16;
	}
	i = ft_strlen(string);
	i = i + ft_print_str("0x");
	ft_putstr(string);
	free(string);
	if (value == 0)
		i += ft_print_char('0');
	return (i);
}
