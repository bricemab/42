/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:17:53 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/05 17:08:58 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/includes/gnl.h"
#include "includes/so_long.h"

t_point	*create_point(int x, int y, char c)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->value = c;
	return (point);
}

void	create_points(t_map **map)
{
	int		i;
	int		j;
	int		k;
	t_point	*point;

	(*map)->points = malloc(sizeof(t_point *) * ((*map)->height + 1));
	init_zero(3, &i, &j, &k);
	while (i < (*map)->height)
	{
		(*map)->points[i] = malloc(sizeof(t_point) * ((*map)->width + 1));
		j = 0;
		while (j < (*map)->width)
		{
			point = create_point(j, i, (*map)->map[i][j]);
			(*map)->points[i][j] = *point;
			free(point);
			j++;
		}
		i++;
	}
	return ;
}

/* si on passe dans ce cas, ca veut dire que les lignes ne sont pas de la
	meme taille
	on se base sur la taille de la premiere ligne */
t_res	*add_new_line(t_map **map, char **line)
{
	if ((*map)->height != 0 && (*map)->width != (int)ft_strlen(*line))
		return (error("Map is not rectangular", MAP_NOT_RECTANGULAR));
	(*map)->map = ft_realloc(
			(*map)->map, sizeof(char *) * ((*map)->height + 1));
	(*map)->map[(*map)->height] = *line;
	(*map)->height++;
	return (success(""));
}

t_res	*read_lines(t_map **map, int fd)
{
	t_res	*res;
	char	*line;

	(*map)->map = malloc(sizeof(char *));
	line = get_next_line(fd);
	if (!line)
		return (error("Map is empty", MAP_EMPTY));
	str_pop(&line);
	(*map)->width = ft_strlen(line);
	res = add_new_line(map, &line);
	while (line != NULL)
	{
		clear_res_type(res);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			str_pop(&line);
		res = add_new_line(map, &line);
	}
	return (success("read_lines() => SUCCESS"));
}

t_res	*checker_map(t_map **map)
{
	t_res	*res;
	int		map_fd;

	map_fd = open((*map)->path, O_RDONLY);
	if (map_fd < 0)
		return (error("path not found", FILE_NOT_FOUND));
	(*map)->height = 0;
	(*map)->width = 0;
	res = read_lines(map, map_fd);
	close(map_fd);
	clear_res_type(res);
	create_points(map);
	show_map(map);
	return (checker_map_build(map));
}
