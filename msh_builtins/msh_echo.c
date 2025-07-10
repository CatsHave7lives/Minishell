/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:01 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/10 09:00:56 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

int	msh_echo(const char **arg)
{
	t_echo	echo;

	if (!arg || !arg[1])
		return (ft_putchar('\n'), EXIT_SUCCESS);
	echo.row = 1;
	echo.flag_n = false;
	while (arg[echo.row] && !ft_strncmp(arg[echo.row], "-n", 2)
		&& ft_str_is_mono(arg[echo.row], 'n', 1))
	{
		echo.flag_n = true;
		echo.row++;
	}
	echo.is_not_first = false;
	while (arg[echo.row])
	{
		if (echo.is_not_first)
			ft_putchar(' ');
		ft_putstr(arg[echo.row]);
		echo.is_not_first = true;
		echo.row++;
	}
	if (!echo.flag_n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
