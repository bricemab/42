/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:14:58 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/30 14:38:40 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_res {
	int		response;
	void	*data;
	char	*error_msg;
}				t_res;

typedef struct s_map {
	char	**map;
	int		height;
	int		width;
	char	*path;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// Clear_mem.c
int		clear_map_response(t_map **map, t_res *res);
void	clear_res_type(t_res *res);

// Utils.c
void	show_map(t_map **map);
t_res	*error(char *str);
t_res	*success(char *str);
void	str_pop(char **str);

// Checker_args.c
t_res	*checker_args(int count, char **args, t_map **map);

// Checker_map.c
t_res	*checker_map(t_map **map);

// Checker_map_build.c
t_res	*checker_map_build(t_map **map);

#endif