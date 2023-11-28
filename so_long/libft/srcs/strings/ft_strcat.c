/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:42:56 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/28 14:12:44 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *str1, char *str2)
{
	int		length;
	char	*r;
	int		i;
	int		j;

	length = ft_strlen(str1);
	length += ft_strlen(str2) + 1;
	r = malloc(sizeof(char) * length);
	i = 0;
	j = 0;
	while (str1[i])
	{
		r[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		r[i] = str2[j];
		j++;
		i++;
	}
	return (r);
}
