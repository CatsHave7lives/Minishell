/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:24:16 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/28 21:32:43 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gc.h"

void	*gc_getcwd(t_gc **gc_head)
{
	t_gc	*node;

	if (!gc_head)
		return (NULL);
	node = malloc(sizeof(t_gc));
	if (!node)
		return (NULL);
	node->ptr = getcwd(NULL, 0);
	if (!node->ptr)
		return (free(node), NULL);
	node->next = *gc_head;
	*gc_head = node;
	return (node->ptr);
}
