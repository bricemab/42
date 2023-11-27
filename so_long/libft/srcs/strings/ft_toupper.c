/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:12:40 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/12 15:05:27 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	If 'c' is a lowercase letter, the function returns its 
	uppercase equivalent otherwise it returns 'c'.
*/

int	ft_toupper(char c)
{
	if (ft_islower(c))
		c -= 32;
	return (c);
}
