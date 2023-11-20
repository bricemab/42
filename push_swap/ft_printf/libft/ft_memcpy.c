/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:21:08 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/10 19:21:10 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
/*
int main() {
	char source[] = "Hello, Waasfdasdfsdfsadforld!";
	char destination[20];

	// Copier les données de source vers destination
	ft_memcpy(destination, source, strlen(source) + 1);

	// Afficher la destination
	printf("Destination: %s\n", destination);

	return 0;
}*/