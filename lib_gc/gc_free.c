/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:20:14 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/03 17:18:41 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gc.h"

void	gc_free(t_gc **gc_head)
{
	t_gc	*gc_node;
	t_gc	*gc_temp;

	gc_node = *gc_head;
	while (gc_node)
	{
		gc_temp = gc_node;
		gc_node = gc_node->next;
		free(gc_temp->ptr);
		free(gc_temp);
	}
	*gc_head = NULL;
	gc_node = NULL;
	gc_temp = NULL;
}
