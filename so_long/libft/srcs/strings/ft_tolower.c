/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:12:21 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/12 15:05:24 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	If 'c' is an uppercase letter, the function returns its 
	lowercase equivalent otherwise it returns 'c'.
*/

int	ft_tolower(char c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
