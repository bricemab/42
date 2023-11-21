/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:55:32 by bmabilla      #+#    #+#             */
/*   Updated: 2023/10/10 21:55:33 by bmabilla     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
/*
int main()
{
	int i;
	int n = 10;
	int * pointer = ft_calloc( n, sizeof(int) );
	for ( i=0; i<n-4; i++ ) {
		pointer[i] = i;
	}
	for (i=0; i<n; i++ ) {
		printf( "%d ", pointer[i] );
	}
	printf( "\n" );
}*/