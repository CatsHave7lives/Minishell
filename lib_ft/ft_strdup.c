/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:28:16 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/29 11:01:32 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

static size_t	static_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*static_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dup;

	if (!s1)
		return (NULL);
	s1_len = static_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dup)
		return (NULL);
	static_strcpy(dup, s1);
	return (dup);
}
