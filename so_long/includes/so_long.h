/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:14:58 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/29 16:08:01 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_res {
	int		response;
	void	*data;
}				t_res;

typedef struct s_map {
	char	**map;
	size_t	height;
	size_t	width;
	char	*path;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

t_res	*error(char *str);
t_res	*success(char *str);
void	str_pop(char **str);
t_res	*checker_args(int count, char **args, t_map **map);
t_res	checker_map(t_map **map);

#endif