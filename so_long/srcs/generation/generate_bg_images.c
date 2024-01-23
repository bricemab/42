/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_bg_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:50:00 by bmabilla          #+#    #+#             */
/*   Updated: 2024/01/23 11:42:49 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	generate_none_bg_img(t_vars *mlx, t_map *map)
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

void	get_corr_x_y(int *corr_x, int *corr_y, t_img img, t_point *ptn)
{
	if (img.height != IMG_SIZE)
	{
		*corr_x = ptn->x * IMG_SIZE + img.height / 2;
		*corr_y = ptn->y * IMG_SIZE + img.width / 2;
	}
	else
	{
		*corr_x = ptn->x * IMG_SIZE;
		*corr_y = ptn->y * IMG_SIZE;
	}
}

int	close_window(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0);
	return (0);
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
