/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:01 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/07 11:53:46 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

int	msh_echo(t_list *av)
{
	t_echo	echo;

	if (!av)
		return (EXIT_SUCCESS);
	echo.flag_n = false;
	while (av && av->str[0] == '-' && ft_str_is_mono(av->str, 'n', 1))
	{
		echo.flag_n = true;
		av = av->next;
	}
	echo.is_first = true;
	while (av)
	{
		if (!echo.is_first)
			ft_putchar(' ');
		ft_putstr(av->str);
		echo.is_first = false;
		av = av->next;
	}
	if (!echo.flag_n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
