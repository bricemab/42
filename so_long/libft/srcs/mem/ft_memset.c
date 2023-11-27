/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:10:39 by bmabilla          #+#    #+#             */
/*   Updated: 2023/03/31 10:13:00 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Fills the first 'n' bytes of the memory area pointed to by 's' with the
	constant byte 'c'.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *) s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}
