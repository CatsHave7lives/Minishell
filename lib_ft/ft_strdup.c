/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:28:16 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/25 10:17:42 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dup;

	s1_len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
