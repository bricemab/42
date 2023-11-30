/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:17:53 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/30 14:43:18 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/includes/gnl.h"
#include "includes/so_long.h"

/* si on passe dans ce cas, ca veut dire que les lignes ne sont pas de la
	meme taille
	on se base sur la taille de la premiere ligne */
t_res	*add_new_line(t_map **map, char **line)
{
	if ((*map)->height != 0 && (*map)->width != (int)ft_strlen(*line))
		return (error("Map is not rectangular"));
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
		return (error("Map is empty"));
	str_pop(&line);
	(*map)->width = ft_strlen(line);
	res = add_new_line(map, &line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			str_pop(&line);
		res = add_new_line(map, &line);
	}
	clear_res_type(res);
	free(line);
	//show_map(map);
	return (success("read_lines() => SUCCESS"));
}

t_res	*checker_map(t_map **map)
{
	//t_res	*res;
	int	map_fd;

	map_fd = open((*map)->path, O_RDONLY);
	if (map_fd < 0)
		return (error(ft_strcat("checker_map() cannot open ", (*map)->path)));
	(*map)->height = 0;
	(*map)->width = 0;
	//res = read_lines(map, map_fd);
	//clear_res_type(res);
	close(map_fd);
	return (success("checker_map() SUCESS"));
}
