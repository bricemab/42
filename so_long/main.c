/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:12:09 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/29 16:18:21 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/ft_printf.h"
#include "includes/so_long.h"
#include "mlx/mlx.h"

int	clear_map_response(t_map **map, t_res *res)
{
	free((*map)->path);
	free((*map));
	free(res);
	return (0);
}

int	main(int count, char **args)
{
	/*void	*mlx;
	void	*mlx_win;
	void    *img;
    int     img_width, img_height;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img = mlx_xpm_file_to_image(mlx, "./images/wall_100-100.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);*/
	t_map	*map;
	t_res	*response = NULL;

	map = malloc(sizeof(t_map));
	response = checker_args(count, args, &map);
	if ((*response).response == 0)
		return (clear_map_response(&map, response));
	clear_map_response(&map, response);
	//checker_map(&map);
	return (1);
}