/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:18:51 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/29 16:07:51 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libft/includes/gnl.h"
#include "libft/includes/libft.h"

t_res	*checker_args(int count, char **args, t_map **map)
{
	int		map_fd;
	char	*filename;

	if (count != 2)
		return (error("checker_args() => argv must egals 2"));
	filename = ft_strcat(args[1], ".ber");
	(*map)->path = ft_strcat("./maps/", filename);
	free(filename);
	map_fd = open((*map)->path, O_RDONLY);
	if (map_fd < 0)
		return (
			error(ft_strcat("checker_args() => path not found: ", (*map)->path))
		);
	close(map_fd);
	return (success("checker_args() => OK"));
}
