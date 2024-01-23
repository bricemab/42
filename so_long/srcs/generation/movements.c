/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:34:35 by bmabilla          #+#    #+#             */
/*   Updated: 2024/01/23 13:49:46 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	win(int nbr_movements)
{
	ft_printf("You win in %d movements", nbr_movements);
	exit(0);
}

int	move_char(t_point *next_ptn, t_player *p, t_vars *mlx)
{
	if (next_ptn->value == MAP_WALL_CHAR)
		return (1);
	if (next_ptn->value == MAP_ITEM_CHAR)
		p->nbr_items++;
	if (next_ptn->value == MAP_EXIT_CHAR)
	{
		if (p->nbr_items != mlx->map->nbr_items)
			return (1);
		else
		{
			mlx->map->nbr_movments++;
			ft_printf("%d moves\n", mlx->map->nbr_movments);
			win(mlx->map->nbr_movments);
			return (1);
		}
	}
	return (0);
}

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
	if (move_char(next_ptn, &p, mlx) == 1)
		return ;
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
