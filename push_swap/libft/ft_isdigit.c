/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:12 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/09 12:56:14 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
	{
		return (1);
	}
	return (0);
}
/*
#include "stdio.h"
int main()
{
	printf("%i", ft_isdigit('2'));
}*/