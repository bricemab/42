#include "libft/libft.h"

int	ft_print_nbr(int c)
{
	int	length;
	int	nbr;

	nbr = c;
	length = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		length++;
	}
	ft_putnbr(c);
	return (length);
}