/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:12:01 by bmabilla      #+#    #+#             */
/*   Updated: 2023/10/09 16:12:03 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	dest_lenght;
	int		src_lenght;

	i = ft_strlen(dest);
	j = 0;
	dest_lenght = ft_strlen(dest);
	src_lenght = ft_strlen(src);
	if (size < 1)
		return (src_lenght + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < dest_lenght)
		return (src_lenght + size);
	else
		return (dest_lenght + src_lenght);
}
/*
int main()
{
	char *src = "efgh";
	char dest[20] = "abcd";
	printf("%c", '\n');
	printf("%lu", strlcat(dest, src, 1));
	printf("%c", '\n');
	printf("%s", dest);
	printf("%c", '\n');
	printf("%lu", strlen(dest));
	printf("%c", '\n');
	printf("%c", '\n');
	src = "efgh";
	char dest2[20] = "abcd";
	printf("%d", ft_strlcat(dest2, src, 1));
	printf("%c", '\n');
	printf("%s", dest2);
	printf("%c", '\n');
	printf("%lu", strlen(dest2));
}
*/