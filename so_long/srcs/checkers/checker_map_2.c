/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:33:43 by bmabilla          #+#    #+#             */
/*   Updated: 2024/01/23 11:38:47 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_point_2(int x, int y, t_map *map)
{
	t_point	*point;

	point = create_point(x, y, map);
	map->points[y][x] = *point;
	if (point->value == MAP_EXIT_CHAR)
		map->exit = *point;
	if (point->value == MAP_SPAWN_CHAR)
	{
		map->spawn = *point;
		map->player = init_player(*point);
	}
	free(point);
}
