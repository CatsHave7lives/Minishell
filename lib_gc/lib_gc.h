/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_gc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:07:59 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/28 17:59:29 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_GC_H
# define LIB_GC_H

# include "minishell.h"

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}	t_gc;

void	gc_free(t_gc *gc_node);
void	*gc_getcwd(t_gc **gc_head);
void	*gc_malloc(size_t size, t_gc **gc_head);

#endif