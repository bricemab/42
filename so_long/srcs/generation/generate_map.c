/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:04:15 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/20 15:32:05 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


t_img	create_img(t_vars *mlx, t_point *ptn, char *path)
{
	t_img	img;
	int		corr_x;
	int		corr_y;

	img.img = mlx_xpm_file_to_image(mlx->mlx, path, &(img.width), &(img.height));
	img.path = path;
	if (!img.img)
	{
		ft_printf("%s not found", path);
		ptn->img = img;
		return (img);
	}
	ptn->has_img = true;
	if (img.height != IMG_SIZE)
	{
		corr_x = ptn->x * IMG_SIZE + img.height / 2;
		corr_y = ptn->y * IMG_SIZE + img.width / 2;
	} 
	else {
		corr_x = ptn->x * IMG_SIZE;
		corr_y = ptn->y * IMG_SIZE;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, corr_x, corr_y);
	
	return (img);
}

char	*get_img_path(t_point ptn, bool is_bg)
{
	if (is_bg && ptn.value != MAP_WALL_CHAR)
		return (IMG_GROUND);
	if (ptn.value == MAP_WALL_CHAR)
		return (IMG_WALL);
	else if (ptn.value == MAP_GROUND_CHAR)
		return (IMG_GROUND);
	else if (ptn.value == MAP_SPAWN_CHAR)
		return (IMG_CHAR);
	else if (ptn.value == MAP_EXIT_CHAR)
		return (IMG_EXIT);
	else if (ptn.value == MAP_ITEM_CHAR)
		return (IMG_ITEMS);
	else
		return (IMG_WALL);
}

t_img	generate_img(t_vars *mlx, t_point *ptn, t_map *map, bool is_bg)
{
	char	*path;
	t_img	img;

	(void)map;
	path = get_img_path(*ptn, is_bg);
	img = create_img(mlx, ptn, path);
	ptn->img = img;
	return (img);
}

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
				img = generate_img(mlx, &(map->points[i][j]), map, false);
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
			generate_img(mlx, &(map->points[i][j]), map, true);
			j++;
		}
		i++;
	}
}

void	generate_map(t_map *map)
{
	t_vars	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, IMG_SIZE * map->width,
			IMG_SIZE * map->height, "SO LONG");
	generate_bg_img(&mlx, map);
	generate_none_bg_img(&mlx, map);
	config_binds(&mlx);
	mlx_loop(mlx.mlx);
}
