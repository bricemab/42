/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:15:02 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/25 14:15:04 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

/*
int main () {
    char letter[20] = "Life if good.";
    ft_putstr_fd(letter, 1);
    return(0);
}
*/