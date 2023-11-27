/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:46:29 by bmabilla          #+#    #+#             */
/*   Updated: 2023/04/01 09:48:47 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns the absolute value
*/

int		ft_abs(int nb)
{
    long long int nbr;

    nbr = nb;    
	if (nbr < 0)
		return (nbr = nbr * -1);
	else
		return (nbr);
}
