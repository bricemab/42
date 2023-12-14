/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:04:15 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/14 13:37:18 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_img(t_mlx *mlx, int x, int y, char *path)
{
	int		img_width;
	int		img_height;
	void	*img;
	int		l;

	l = MAP_IMAGE_SIZE;
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	if (!img)
	{
		ft_printf("%s not found", path);
		return ;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, img_height * x, img_width * y);
}

char	*get_correct_map_image(t_map **map, int x, int y)
{
	t_point	*ptn;

	ptn = &(*map)->points[y][x];
	if ((*ptn).value == MAP_WALL_CHAR)
		return ("./images/wall_50x50.xpm");
	else if ((*ptn).value == MAP_GROUND_CHAR)
		return ("./images/ground_50x50.xpm");
	else if ((*ptn).value == MAP_SPAWN_CHAR)
		return ("./images/char_50x50.xpm");
	else if ((*ptn).value == MAP_EXIT_CHAR)
		return ("./images/door_50x50.xpm");
	else if ((*ptn).value == MAP_ITEM_CHAR)
		return ("./images/item_50x50.xpm");
	else
		return ("./images/wall_50x50.xpm");
}

void	create_correct_image(t_mlx *mlx, int x, int y, t_map **map)
{
	t_point	*ptn;

	ptn = &(*map)->points[y][x];
	if ((*ptn).value == MAP_SPAWN_CHAR)
	{
		create_img(mlx, x, y, "./images/ground_50x50.xpm");
		create_img(mlx, x, y, get_correct_map_image(map, x, y));
	}
	else
		create_img(mlx, x, y, get_correct_map_image(map, x, y));
}

void	generate_map(t_map **map)
{
	t_mlx	*mlx;
	void	*mlx_ini;
	void	*mlx_win;
	int		i;
	int		j;

	mlx = malloc(sizeof(t_mlx));
	mlx_ini = mlx_init();
	mlx_win = mlx_new_window(mlx_ini, IMG_SIZE * (*map)->width,
			IMG_SIZE * (*map)->height, "Game");
	mlx->mlx = mlx_ini;
	mlx->win = mlx_win;
	init_zero(2, &i, &j);
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->width)
		{
			//create_img(mlx, j, i, get_correct_map_image(map, j, i));
			create_correct_image(mlx, j, i, map);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ini);
}
