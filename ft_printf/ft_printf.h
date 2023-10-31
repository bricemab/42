#ifndef FT_PRINTF
#define FT_PRINTF

# include "libft/libft.h"
# include "stdarg.h"

int ft_printf(const char *, ...);

int	ft_print_hex(unsigned int value, int asc);
int	ft_print_ptr(unsigned long value, int asc);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_char(int c);
int	ft_print_nbr(int c);
int	ft_print_str(char *str);
int	ft_print_percent();

#endif