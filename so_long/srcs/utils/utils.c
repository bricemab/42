/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:31 by bmabilla          #+#    #+#             */
/*   Updated: 2023/12/20 12:10:13 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/includes/ft_printf.h"
#include "../../libft/includes/libft.h"

void	show_map(t_map *map)
{
	int		i;
	int		j;
	t_point	point;

	ft_printf("Map Height: %d\n", map->height);
	ft_printf("Map Width: %d\n", map->width);
	init_zero(2, &i, &j);
	while (i < map->height)
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			point = map->points[i][j];
			ft_printf("x = %d | y = %d | value = %c\n", point.x, point.y, point.value);
			j++;
		}
		i++;
	}
}

void	str_pop(char **str)
{
	(*str)[ft_strlen(*str) - 1] = '\0';
}

t_res	*error(char *str, int code)
{
	t_res	*res;

	res = malloc(sizeof(t_res));
	(*res).response = 0;
	(*res).code = code;
	ft_printf("Error\n");
	if (ft_strlen(str) != 0)
		ft_printf("%s\n", str);
	return (res);
}

t_res	*success(char *str)
{
	t_res	*res;

	res = malloc(sizeof(t_res));
	res->response = 1;
	str = ft_strcat(str, "");
	if (ft_strlen(str) != 0)
		ft_printf("%s\n", str);
	free(str);
	return (res);
}

void	init_zero(int count, ...)
{
	va_list	args;
	int		*curr;
	int		i;

	i = 0;
	va_start(args, count);
	while (i < count)
	{
		curr = va_arg(args, int *);
		*curr = 0;
		i++;
	}
	va_end(args);
}
