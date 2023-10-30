/* *************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:59:23 by obibik            #+#    #+#             */
/*   Updated: 2018/08/22 16:59:25 by obibik           ###   ########.fr       */
/*                                                                            */
/* *************************************************************************/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char            *str;

    i = 0;
    str = malloc(sizeof(s) * (ft_strlen(s) + 1));
    if (!str)
        return (NULL);
    while (s[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

/*
char my_func(unsigned int i, char str)
{
	printf("My inner function: index = %d and %c\n", i, str);
	return str - 32;
}

int main()
{
	char str[10] = "hello.";
	printf("The result is %s\n", str);
	char *result = ft_strmapi(str, my_func);
	printf("The result is %s\n", result);
	return 0;
}

*/