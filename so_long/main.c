/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:12:09 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/12 14:24:46 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "mlx/mlx.h"

int	valid_args_map(int count, char **args, t_map **map)
{
	t_res	*response;

	response = checker_args(count, args, map);
	if ((*response).response == 0)
		return (clear_map_response(map, response));
	clear_res_type(response);
	response = checker_map(map);
	if ((*response).response == 0)
		return (clear_map_response(map, response));
	clear_res_type(response);
	response = checker_pathfinding(map);
	return (clear_map_response(map, response));
}

int	main(int count, char **args)
{
	t_map	*map;
	//t_res	*response;

	map = malloc(sizeof(t_map));
	if (!map)
		return (
			clear_map_response(&map, error("Map not allocate", MISSING_ARGS)));
	valid_args_map(count, args, &map);
	generate_map(&map);
	// return (clear_map_response(&map, response));
	return (1);
}
