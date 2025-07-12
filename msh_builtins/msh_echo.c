/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:01 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 07:53:49 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

int	msh_echo(const char **arg)
{
	t_echo	echo;

	echo.arg = 1;
	if (!arg || !arg[echo.arg])
		return (ft_putchar('\n'), EXIT_SUCCESS);
	echo.flag_n = false;
	while (arg[echo.arg] && !ft_strncmp(arg[echo.arg], "-n", 2)
		&& ft_str_is_mono(arg[echo.arg], 'n', 1))
	{
		echo.flag_n = true;
		echo.arg++;
	}
	echo.is_not_first = false;
	while (arg[echo.arg])
	{
		if (echo.is_not_first)
			ft_putchar(' ');
		ft_putstr(arg[echo.arg]);
		echo.is_not_first = true;
		echo.arg++;
	}
	if (!echo.flag_n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
