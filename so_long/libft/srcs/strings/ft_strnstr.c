/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:38:57 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/05 17:08:58 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Locates the first occurrence of the null-terminated string little in the 
	string 'big', where not more than 'len' characters are searched.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		x = 0;
		while (big[i + x] && little[x]
			&& i + x < len && big[i + x] == little[x])
			x++;
		if (!little[x])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
