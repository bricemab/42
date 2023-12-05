/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:12:09 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/05 17:08:58 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/ft_printf.h"
#include "includes/so_long.h"
#include "mlx/mlx.h"

/*
	void	*mlx;
	void	*mlx_win;
	void    *img;
    int     img_width, img_height;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img = mlx_xpm_file_to_image(mlx, "./images/wall_100-100.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);*/
int	main(int count, char **args)
{
	t_map	*map;
	t_res	*response;

	map = malloc(sizeof(t_map));
	if (!map)
		return (
			clear_map_response(&map, error("Map not allocate", MISSING_ARGS)));
	response = checker_args(count, args, &map);
	if ((*response).response == 0)
		return (clear_map_response(&map, response));
	clear_res_type(response);
	response = checker_map(&map);
	if ((*response).response == 0)
		return (clear_map_response(&map, response));
	return (clear_map_response(&map, response));
}
