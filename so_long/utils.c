/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:31 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/28 13:30:46 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libft/includes/ft_printf.h"

void    throw_error(char *str)
{
    ft_printf("Error\n");
    ft_printf("%s\n", str);
    exit(1);
}