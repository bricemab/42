/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:12:09 by bmabilla          #+#    #+#             */
/*   Updated: 2024/01/10 12:44:10 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "mlx/mlx.h"

int	main(int count, char **args)
{
	t_map	map;
	t_res	*response;

	response = checker_args(count, args, &map);
	if ((*response).response == 0)
		return (clear_map_response(&map, response));
	clear_res_type(response);
	response = checker_map(&map);
	if ((*response).response == 0)
		return (clear_map_response(&map, response));
	clear_res_type(response);
	response = checker_pathfinding(&map);
	if ((*response).response == 0)
		return (clear_map_response(&map, response));
	generate_map(&map);
	return (clear_map_response(&map, response));
}
