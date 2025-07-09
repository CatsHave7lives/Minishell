/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:45:33 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/08 21:41:00 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

static int	static_is_sign(const char c)
{
	return (c == '+' || c == '-');
}

static int	static_is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

static bool	ft_str_is_digit(const char *str)
{
	const char	*digit;

	if (!str || !str[0])
		return (false);
	digit = str;
	while (static_is_digit(*digit))
		digit++;
	if (*digit)
		return (false);
	return (true);
}

bool	ft_str_is_number(const char *str)
{
	const char	*digit;

	if (!str || !str[0])
		return (false);
	digit = str;
	if (static_is_sign(*digit))
		digit++;
	if (!ft_str_is_digit(digit))
		return (false);
	return (true);
}
