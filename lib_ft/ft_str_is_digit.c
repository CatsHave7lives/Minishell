/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:45:33 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/08 06:04:25 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

static int	static_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (false);
	return (true);
}
