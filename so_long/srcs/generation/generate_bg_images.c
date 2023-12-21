/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_bg_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:50:00 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/21 14:17:44 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void generate_none_bg_img(t_vars *mlx, t_map *map)
{
	int		i;
	int		j;
	t_point	*ptn;
	t_img	img;

	init_zero(2, &i, &j);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ptn = &(map->points[i][j]);
			if (!(ptn->value == MAP_GROUND_CHAR || ptn->value == MAP_WALL_CHAR))
			{
				img = generate_img(mlx, &(map->points[i][j]), false);
				ptn->has_img = true;
				ptn->img = img;
			}
			j++;
		}
		i++;
	}
}

void	generate_bg_img(t_vars *mlx, t_map *map)
{
	int	i;
	int	j;

	init_zero(2, &i, &j);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			generate_img(mlx, &(map->points[i][j]), true);
			j++;
		}
		i++;
	}
}