/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:37:26 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/06 11:55:21 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	clear_map_response(t_map **map, t_res *res)
{
	int	i;

	init_zero(1, &i);
	if (!((*res).code == FILE_NOT_FOUND || (*res).code == MISSING_ARGS))
	{
		while (i < (*map)->height)
		{
			free((*map)->map[i]);
			free((*map)->points[i]);
			i++;
		}
		free((*map)->points);
		free((*map)->map);
	}
	if ((*res).code != MISSING_ARGS)
		free((*map)->path);
	free((*map));
	clear_res_type(res);
	return (0);
}

void	clear_res_type(t_res *res)
{
	free(res);
}
