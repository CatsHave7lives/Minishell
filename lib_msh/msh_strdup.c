/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:16:41 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/18 14:50:21 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_msh.h"

void	*msh_strdup(const char *str, t_gc **gc_head)
{
	size_t	str_len;
	char	*dup;

	str_len = ft_strlen(str);
	msh_malloc(&dup, (sizeof(char) * (str_len +1)), gc_head);
	ft_strcpy(dup, str);
	return (dup);
}
