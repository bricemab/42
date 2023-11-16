/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:15:42 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/25 14:15:44 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

/*
void my_func(unsigned int i, char *str)
{
	printf("My inner function: index = %d and the string is %s\n", i, str);
}

int main()
{
	char str[10] = "Hello.";
	printf("The result is %s\n", str);
	ft_striteri(str, my_func);
	printf("The result is %s\n", str);
	return 0;
}*/
