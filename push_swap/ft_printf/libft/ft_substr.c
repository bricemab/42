/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:57:31 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/11 15:57:33 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_size(size_t str_len, size_t start, size_t len)
{
	if (str_len - start >= len)
		return (len + 1);
	return (str_len - start + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen((char *)s);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start >= len)
		str = (char *)malloc((len + 1) * sizeof(char));
	else
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), get_size(str_len, start, len));
	return (str);
}
/*
int main()
{
	printf("%s", ft_substr("zebi", 2, 999999999999));
}*/