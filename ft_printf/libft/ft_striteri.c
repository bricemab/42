/* *************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:58:34 by obibik            #+#    #+#             */
/*   Updated: 2018/08/22 16:58:37 by obibik           ###   ########.fr       */
/*                                                                            */
/* *************************************************************************/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int    i;

    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
    s[i] = '\0';
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
}
*/
