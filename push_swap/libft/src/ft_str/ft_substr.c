/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:27:11 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 12:27:56 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*s_over(void)
{
	char	*out;

	out = (char *)malloc(sizeof(char));
	if (!out)
		return (NULL);
	out[0] = '\0';
	return (out);
}

static char	*s_equal(const char *s)
{
	char	*out;

	out = (char *)malloc(sizeof(char) * 2);
	if (!out)
		return (NULL);
	out[0] = s[ft_strlen(s) - 1];
	out[1] = '\0';
	return (out);
}

static char	*l_over(const char *s, size_t start)
{
	char	*out;
	size_t	i;

	out = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (s[i + start])
	{
		out[i] = s[i + start];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (start > ft_strlen(s) - 1 || ft_strlen(s) == 0)
		out = s_over();
	else if (start == ft_strlen(s) - 1 && len != 0)
		out = s_equal(s);
	else if (len > ft_strlen(s) - start - 1)
		out = l_over(s, start);
	else
	{
		out = (char *) malloc((len + 1) * sizeof(char));
		if (!out)
			return (NULL);
		i = 0;
		while (i < len)
		{
			out[i] = s[i + start];
			i++;
		}
		out[i] = '\0';
	}
	return (out);
}
