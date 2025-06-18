/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 06:54:22 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/15 06:55:04 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_msh.h"

void	msh_malloc(void **ptr, size_t size, t_gc **gc_head)
{
	*ptr = gc_malloc(size, gc_head);
	if (!*ptr)
	{
		gc_free(*gc_head);
		perror("msh");
		exit(2);
	}
}
