/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:24:33 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/21 13:32:27 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_player	init_player(t_point ptn)
{
	t_player player;

	player.nbr_items = 0;
	player.pos = ptn;
	return (player);
}