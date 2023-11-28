/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:12:09 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/28 14:34:29 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/ft_printf.h"
#include "includes/so_long.h"
#include "mlx/mlx.h"

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
	checker_args(count, args);
	checker_map();
}