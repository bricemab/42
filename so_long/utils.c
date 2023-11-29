/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:31 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/29 16:10:59 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libft/includes/ft_printf.h"

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
    ft_printf("Error\n");
    ft_printf("%s\n", str);
	free(str);
    return (res);
}

t_res	*success(char *str)
{
	t_res	*res;

	res = malloc(sizeof(t_res));
	(*res).response = 1;
    ft_printf("%s\n", str);
	//free(str);
    return (res);
}