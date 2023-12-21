/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:34:35 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/21 15:33:07 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move(t_vars *mlx, int add_x, int add_y)
{
	t_point		*ptn;
	t_point		*next_ptn;
	t_player	p;

	p = mlx->map->player;
	ptn = &(mlx->map->points[p.pos.y][p.pos.x]);
	p.pos.y += add_y;
	p.pos.x += add_x;
	next_ptn = &(mlx->map->points[p.pos.y][p.pos.x]);
	if (next_ptn->value == MAP_WALL_CHAR)
		return ;
	if (next_ptn->value == MAP_ITEM_CHAR)
		p.nbr_items++;
	if (next_ptn->value == MAP_EXIT_CHAR)
	{
		if (p.nbr_items != mlx->map->nbr_items)
			return ;
		else
			return exit(0);
	}
	mlx->map->nbr_movments++;
	ft_printf("%d moves\n", mlx->map->nbr_movments);
	mlx->map->player = p;
	generate_img(mlx, ptn, true);
	ptn->value = MAP_GROUND_CHAR;
	*next_ptn = p.pos;
	generate_img(mlx, next_ptn, true);
	generate_img(mlx, next_ptn, false);
}

int	hook_binds(int key, t_vars *mlx)
{	
	t_map	*map;

	map = mlx->map;
	if (key == BIND_ESC || key == BIND_Q)
		exit(0);
	if (key == BIND_UP)
		move(mlx, 0, -1);
	if (key == BIND_DOWN)
		move(mlx, 0, 1);
	if (key == BIND_LEFT)
		move(mlx, -1, 0);
	if (key == BIND_RIGHT)
		move(mlx, 1, 0);
	return (0);
}