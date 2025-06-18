/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:20:14 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/15 06:55:12 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gc.h"

void	gc_free(t_gc *gc_node)
{
	t_gc	*gc_temp;

	while (gc_node)
	{
		gc_temp = gc_node;
		gc_node = gc_node->next;
		free(gc_temp->ptr);
		free(gc_temp);
	}
}
