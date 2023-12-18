/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:34:35 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/18 12:37:10 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	hook_binds(int key, t_vars *vars)
{
	(void)vars;
	
	printf("Hello from key_hook! %d => %c\n", key, key);
	return (0);
}

void	config_binds(t_vars *mlx)
{
	mlx_key_hook((*mlx).win, hook_binds, mlx);
}