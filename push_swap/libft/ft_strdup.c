/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:08:12 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/11 14:08:13 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		length;

	length = ft_strlen(s1) + 1;
	ptr = malloc(sizeof(char) * length);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, length);
	return (ptr);
}
/*
int main() {

	const char * original = "The original string.";

	char * copy = ft_strdup( original );
	printf( "%s\n", copy );
	free( copy );

	return EXIT_SUCCESS;
}*/