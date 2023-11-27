/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:06:34 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/14 15:50:11 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Erases the data in the 'n' bytes of the memory starting at the location
	pointed to by 's' by writing null characters '\0' to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	if (!s)
		return ;
	ptr = (char *) s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
