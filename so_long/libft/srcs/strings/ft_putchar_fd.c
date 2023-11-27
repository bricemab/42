/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:42:19 by bmabilla          #+#    #+#             */
/*   Updated: 2023/03/31 10:12:30 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Writes the character 'c' on the given file descriptor
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
