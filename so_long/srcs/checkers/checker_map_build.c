/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_build.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:33:05 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/21 13:32:52 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_res	*round_by_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		if (!(map->map[i][0] == MAP_WALL_CHAR
			&& map->map[i][map->width - 1] == MAP_WALL_CHAR))
			return (error("Map missing wallff", MAP_NOT_ROUND_BY_WALL));
		if (i == 0 || i == map->height - 1)
		{
			while (j < map->width)
			{
				if (map->map[i][j] != MAP_WALL_CHAR)
					return (error("Map missing wall", MAP_NOT_ROUND_BY_WALL));
				j++;
			}
		}
		i++;
	}
	return (success(""));
}

void	incr_nbr_map(char ch, int *exit, int *spawn, int *items)
{
	if (ch == MAP_EXIT_CHAR)
		(*exit)++;
	if (ch == MAP_SPAWN_CHAR)
		(*spawn)++;
	if (ch == MAP_ITEM_CHAR)
		(*items)++;
}

t_res	*has_spawn_exit_items(t_map *map)
{
	int	exit;
	int	items;
	int	spawn;
	int	i;
	int	j;

	init_zero(5, &exit, &items, &spawn, &i, &j);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			incr_nbr_map(map->map[i][j], &exit, &spawn, &items);
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (error("Must have one \"E\" in the map", MAP_MISSING_EXIT));
	if (spawn != 1)
		return (error("Must have one \"P\" in the map", MAP_MISSING_SPAWN));
	if (items == 0)
		return (error("At least one \"C\" in the map", MAP_MISSING_ITEMS));
	return (success(""));
}

t_res	*checker_map_build(t_map *map)
{
	t_res	*res;

	res = round_by_walls(map);
	if ((*res).response == 0)
		return (res);
	clear_res_type(res);
	res = has_spawn_exit_items(map);
	return (res);
}
