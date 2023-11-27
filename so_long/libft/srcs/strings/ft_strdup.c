/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:36:43 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/12 15:04:27 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns a pointer to a new string which is a duplicate of the string 's'
*/

char	*ft_strdup(const char *s)
{
	char	*str;
	int		src_len;
	int		i;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	str = malloc(sizeof(char) * (src_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
