/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:34:35 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/20 13:31:36 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	hook_binds(int key, t_vars *mlx)
{	
	(void)mlx;
	ft_printf("Hello from key_hook! %d\n", key);
	if (key == BIND_UP)
	{
		printf("Exit windows\n");
		exit(1);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->mlx);
	}
	return (0);
}

void	config_binds(t_vars *mlx)
{
	mlx_key_hook(mlx->win, hook_binds, &mlx);
}