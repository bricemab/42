/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:04:15 by bmabilla          #+#    #+#             */
/*   Updated: 2024/01/23 11:43:30 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_img	create_img(t_vars *mlx, t_point *ptn, char *path)
{
	t_img	img;
	int		corr_x;
	int		corr_y;

	img.img = mlx_xpm_file_to_image(
			mlx->mlx, path, &(img.width), &(img.height));
	img.path = path;
	if (!img.img)
	{
		ft_printf("%s not found", path);
		ptn->img = img;
		return (img);
	}
	ptn->has_img = true;
	get_corr_x_y(&corr_x, &corr_y, img, ptn);
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

t_img	generate_img(t_vars *mlx, t_point *ptn, bool is_bg)
{
	char	*path;
	t_img	img;

	path = get_img_path(*ptn, is_bg);
	img = create_img(mlx, ptn, path);
	ptn->img = img;
	return (img);
}

void	config_binds(t_vars *mlx)
{
	mlx_key_hook(mlx->win, hook_binds, mlx);
}

void	generate_map(t_map *map)
{
	t_vars	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, IMG_SIZE * map->width,
			IMG_SIZE * map->height, "SO LONG");
	mlx.map = map;
	generate_bg_img(&mlx, map);
	generate_none_bg_img(&mlx, map);
	config_binds(&mlx);
	mlx_hook(mlx.win, 17, 0, close_window, NULL);
	mlx_loop(mlx.mlx);
}
