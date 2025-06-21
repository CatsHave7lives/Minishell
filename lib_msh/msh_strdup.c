/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:16:41 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/21 13:38:31 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_msh.h"

void	*msh_strdup(const char *str, t_gc **gc)
{
	if (!ft_strdup(str))
	{
		gc_free(*gc);
		perror("msh");
		exit(2);
	}
	return (dup);
}
