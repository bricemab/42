/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:03 by bmabilla          #+#    #+#             */
/*   Updated: 2023/03/31 10:13:10 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Adds the node at the beginning of the linked list
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		new->next = *lst;
		*lst = new;
	}
}
