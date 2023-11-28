/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:18:51 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/28 14:34:40 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libft/includes/gnl.h"
#include "libft/includes/libft.h"

void	checker_args(int count, char **args)
{
	int		map;
	char	*path;

	if (count != 2)
		return (error("checker_args() => argv must egals 2"));
	path = ft_strcat("./maps/", ft_strcat(args[1], ".bre"));
	map = open(path, O_RDONLY);
	if (map < 0)
		return (
			error(ft_strcat("checker_args() => cannot find the path: ", path))
		);
	close(map);
}
