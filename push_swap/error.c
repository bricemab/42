/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:32 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/20 13:19:34 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(char *fn)
{
	// red
	ft_printf("\033[1;31m");
	ft_printf("%e");
	ft_printf("%s\n", fn);
	fn = NULL;
	// reset => black
	ft_printf("\033[0m");
	exit(EXIT_FAILURE);
}
