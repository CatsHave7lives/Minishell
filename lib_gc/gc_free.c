/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:20:14 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/09 05:11:34 by aessaber         ###   ########.fr       */
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
		ft_free((void **)&gc_temp->ptr);
		ft_free((void **)&gc_temp);
	}
	*gc_head = NULL;
}
