/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:15:49 by bmabilla      #+#    #+#             */
/*   Updated: 2023/11/01 12:15:51 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include "stdarg.h"

int	ft_printf(const char *string, ...);

int	ft_print_hex(unsigned int value, int asc);
int	ft_print_ptr(unsigned long value, int asc);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_char(int c);
int	ft_print_nbr(int c);
int	ft_print_str(char *str);
int	ft_print_percent(void);

#endif
