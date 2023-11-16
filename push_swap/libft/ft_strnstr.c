/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:38 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/10 18:39:40 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*str;

	i = 0;
	str = (char *)s1;
	n_len = ft_strlen(s2);
	if (n_len == 0 || s1 == s2)
		return (str);
	while (str[i] != '\0' && i < n)
	{
		c = 0;
		while (str[i + c] != '\0' && s2[c] != '\0'
			&& str[i + c] == s2[c] && i + c < n)
			c++;
		if (c == n_len)
			return (str + i);
		i++;
	}
	return (0);
}
/*
int main()
{
	printf("%s", ft_strnstr("test", "ffes", 4));
}*/