/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:37:26 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/30 14:44:56 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	clear_map_response(t_map **map, t_res *res)
{
	int	i;

	i = 0;
	while (i < (*map)->height)
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
	free((*map)->path);
	free((*map));
	clear_res_type(res);
	return (0);
}

void	clear_res_type(t_res *res)
{
	if ((*res).error_msg)
		free((*res).error_msg);
	free(res);
}