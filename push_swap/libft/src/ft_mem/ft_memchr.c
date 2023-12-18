/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:20:55 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/09 12:20:59 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	letter;
	size_t			index;

	str = (unsigned char *)s;
	letter = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (str[index] == letter)
			return (str + index);
		index++;
	}
	return (NULL);
}
