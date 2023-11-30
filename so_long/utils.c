/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:31 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/30 14:37:34 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"

void	show_map(t_map **map)
{
	int	i;

	ft_printf("Map Height: %d\n", (*map)->height);
	ft_printf("Map Width: %d\n", (*map)->width);
	i = 0;
	while (i < (*map)->height)
	{
		ft_printf("%s\n", (*map)->map[i]);
		i++;
	}
}

void	str_pop(char **str)
{
	int		i;
	char	*res;

	i = 0;
	res = *str;
	*str = NULL;
	*str = malloc(sizeof(char) * ft_strlen(res));
	while (i < ((int)ft_strlen(res) - 1))
	{
		(*str)[i] = res[i];
		i++;
	}
	(*str)[i] = '\0';
}

t_res	*error(char *str)
{
	t_res	*res;

	res = malloc(sizeof(t_res));
	(*res).response = 0;
	str = ft_strcat(str, "");
    ft_printf("Error\n");
	if (ft_strlen(str) != 0)
    	ft_printf("%s\n", str);
	(*res).error_msg = str;
	free(str);
    return (res);
}

t_res	*success(char *str)
{
	t_res	*res;

	res = malloc(sizeof(t_res));
	(*res).response = 1;
	str = ft_strcat(str, "");
	if (ft_strlen(str) != 0)
    	ft_printf("%s\n", str);
	free(str);
    return (res);
}