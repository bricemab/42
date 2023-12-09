/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pathfinding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:25:27 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/06 11:59:51 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	visiteNode(int x, int y, int items, t_map **map)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	*point = (*map)->points[y][x];
	if (x < 0 || y < 0 || y >= (*map)->height || x >= (*map)->width)
		return ;
	if (point->treated == 1)
		return ;
	if (point->value == MAP_WALL_CHAR)
		return ;
	if (point->value == MAP_ITEM_CHAR)
		items++;
	if (point->value == MAP_EXIT_CHAR)
		(*map)->valid_exit = 1;
	if (items == (*map)->nbr_items)
		(*map)->valid_items = 1;
	point->treated = 1;
	visiteNode(x, y + 1, items, map);
	visiteNode(x, y - 1, items, map);
	visiteNode(x + 1, y, items, map);
	visiteNode(x - 1, y, items, map);
}

t_res	*checker_pathfinding(t_map **map)
{
	t_point	*spawn;

	spawn = malloc(sizeof(t_point));
	*spawn = (*map)->spawn;
	visiteNode(spawn->x, spawn->y, 0, map);
	if ((*map)->valid_exit == 1)
		return (error("", MAP_PATHFINDING_ERROR));
	if ((*map)->valid_exit == 1)
		return (error("", MAP_PATHFINDING_ERROR));
	
	return (success("TODO: pathfinding heree"));
}