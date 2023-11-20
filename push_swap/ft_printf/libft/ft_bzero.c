/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:15:32 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/10 19:15:33 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *) s + i) = 0;
		i++;
	}
}
/*
int main () {
	char str[50];

	strcpy(str,"This is a string");
	puts(str);

	ft_bzero(str, 2);
	puts(str);

	printf("%s", str);
	return(0);
}*/