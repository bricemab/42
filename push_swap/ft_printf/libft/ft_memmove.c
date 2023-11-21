/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:10:09 by bmabilla      #+#    #+#             */
/*   Updated: 2023/10/10 20:10:10 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
/*
int main() {
	char buffer[20] = "Hello, World!";

	// Déplacer "World!" au début de la chaîne en utilisant memmove
	ft_memmove(buffer, buffer+7, strlen(buffer));

	//printf("%s\n", buffer+3);
	// Afficher le résultat
	printf("Résultat : -%s-\n", buffer);

	return 0;
}*/