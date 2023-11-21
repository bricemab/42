/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:34:52 by bmabilla      #+#    #+#             */
/*   Updated: 2023/10/10 20:34:53 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main() {
	char str[] = "Hello, World!";
	char target = 'W';

	// Utilisation de memchr pour rechercher la première occurrence de 'W'
	char *result = (char *)ft_memchr(str, target, strlen(str));

	if (result != NULL) {
		printf("Caractère trouvé à la position : %ld\n", result - str);
	} else {
		printf("Caractère non trouvé.\n");
	}

	return 0;
}
*/