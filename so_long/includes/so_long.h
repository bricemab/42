/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:14:58 by bmabilla          #+#    #+#             */
/*   Updated: 2024/01/23 13:53:38 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/gnl.h"
# include "../mlx/mlx.h"

// Codes errors
# define MAP_NOT_LOAD 500
# define FILE_NOT_FOUND 501
# define MISSING_ARGS 502
# define MAP_NOT_RECTANGULAR 503
# define MAP_EMPTY 504
# define MAP_MISSING_SPAWN 505
# define MAP_MISSING_EXIT 506
# define MAP_MISSING_ITEMS 507
# define MAP_PATHFINDING_ERROR 508
# define MAP_NBR_ITEMS_ERROR 509
# define MAP_NOT_ROUND_BY_WALL 510
# define MAP_INVALID_PATHFINDING 511
# define MALLOC_ERROR 512

// Map Settings
# define MAP_WALL_CHAR '1'
# define MAP_GROUND_CHAR '0'
# define MAP_SPAWN_CHAR 'P'
# define MAP_EXIT_CHAR 'E'
# define MAP_ITEM_CHAR 'C'
# define MAP_IMAGE_SIZE 50
# define IMG_SIZE 50

// Keyboard Binds
# define BIND_ESC 53
# define BIND_Q 12
# define BIND_UP 13
# define BIND_DOWN 1
# define BIND_LEFT 0
# define BIND_RIGHT 2

// Images
# define IMG_WALL "./images/wall_50x50.xpm"
# define IMG_GROUND "./images/ground_50x50.xpm"
# define IMG_CHAR "./images/char.xpm"
# define IMG_ITEMS "./images/body-1_25x25.xpm"
# define IMG_EXIT "./images/door_50x50.xpm"

// Image of a Point
typedef struct s_img {
	void	*img;
	char	*path;
	int		height;
	int		width;
}				t_img;

// Response type
typedef struct s_res {
	int		response;
	void	*data;
	char	*error_msg;
	int		code;
}				t_res;

// Point on map
typedef struct s_point {
	int		x;
	int		y;
	char	value;
	int		treated;
	bool	has_img;
	t_img	img;
}				t_point;

// Player
typedef struct s_player {
	int		nbr_items;
	char	*file;
	t_point	pos;
}				t_player;

// Structur of the map
typedef struct s_map {
	char		**map;
	int			height;
	int			width;
	int			nbr_items;
	int			valid_exit;
	int			valid_items;
	int			nbr_movments;
	char		*path;
	t_point		spawn;
	t_point		exit;
	t_point		**points;
	t_player	player;
}				t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// Clear_mem.c
int			clear_map_response(t_map *map, t_res *res);
void		clear_res_type(t_res *res);

// Utils.c
void		show_map(t_map *map);
t_res		*error(char *str, int code);
t_res		*success(char *str);
void		str_pop(char **str);
void		init_zero(int count, ...);

// Checker_args.c
t_res		*checker_args(int count, char **args, t_map *map);

// Checker_map.c
t_res		*checker_map(t_map *map);
t_point		*create_point(int x, int y, t_map *map);

// Checker_map_2.c
void		create_point_2(int x, int y, t_map *map);

// Checker_map_build.c
t_res		*round_by_walls(t_map *map);
t_res		*checker_map_build(t_map *map);
t_res		*has_spawn_exit_items(t_map *map);

// Checker_pathfinding
t_res		*checker_pathfinding(t_map *map);

// Generate_map
void		generate_map(t_map *map);
t_img		generate_img(t_vars *mlx, t_point *ptn, bool is_bg);

// Movements
int			hook_binds(int key, t_vars *vars);

//Generate bg images
void		get_corr_x_y(int *corr_x, int *corr_y, t_img img, t_point *ptn);
void		generate_none_bg_img(t_vars *mlx, t_map *map);
void		generate_bg_img(t_vars *mlx, t_map *map);
int			close_window(int keycode, void *param);

//Player
t_player	init_player(t_point ptn);
#endif