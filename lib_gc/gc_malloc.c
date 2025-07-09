/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:38:53 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/09 05:15:51 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gc.h"

void	*gc_malloc(size_t size, t_gc **gc_head)
{
	t_gc	*node;

	if (!gc_head)
		return (NULL);
	node = malloc(sizeof(t_gc));
	if (!node)
		return (NULL);
	node->ptr = malloc(size);
	if (!node->ptr)
	{
		ft_free((void **)&node);
		return (NULL);
	}
	node->next = *gc_head;
	*gc_head = node;
	return (node->ptr);
}
