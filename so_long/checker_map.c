/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:17:53 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/28 14:49:59 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include "libft/includes/gnl.h"

int	get_map_height
{
	int	i;

	map = open(path, O_RDONLY);
	if (map < 0)
	{
		error(ft_strcat("get_map_height() => ", path));
		return (0);
	}
	while (get_next_line(map))
		i++;
	close(map);
	return (i);
}

int	is_map_surround_wall(int map)
{
	
}

void	checker_map(char	*path)
{
	int	map;

	map = open(path, O_RDONLY);
	if (map < 0)
		return (error(ft_strcat("checker_map() => ", path)));
	
}