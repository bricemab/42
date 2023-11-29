/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:17:53 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/29 16:08:39 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include "libft/includes/gnl.h"
# include "includes/so_long.h"
/*
int	get_map_height(char *path)
{
	int		i;
	int		map;

	map = open(path, O_RDONLY);
	if (map < 0)
	{
		error(ft_strcat("get_map_height() => ", path));
		return (0);
	}
	i = 0;
	while (get_next_line(map))
		i++;
	close(map);
	return (i);
}

void	read_line(t_map **map)
{
	int		i;
	char	*line;

	
	(void)map;
	(void)line;
	(void)i;
}

t_res	checker_map(t_map **map)
{
	int	map_fd;

	printf("%s\n", (*map)->path);
	map_fd = open((*map)->path, O_RDONLY);
	if (map_fd < 0)
		return (error(ft_strcat("checker_map() => ", (*map)->path)));
	read_line(map);
	return (success("checker_map() => SUCESS"));
}*/