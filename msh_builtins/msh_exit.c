/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:28 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 08:05:24 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

int	msh_exit(const char **arg, int status, t_env **env, t_gc **gc)
{
	t_exit	exit;

	if (!env || !gc)
		return (dbg_nullarg(__func__), EXIT_FAILURE);
	exit.arg = 1;
	if (!arg || !arg[exit.arg])
	{
		ft_putstr("exit\n");
		msh_quit(status, env, gc);
	}
	if (!ft_str_is_num(arg[exit.arg]))
	{
		ft_puterr("msh: exit: ");
		ft_puterr(arg[exit.arg]);
		ft_puterr(": numeric argument required\n");
		msh_quit(UINT8_MAX, env, gc);
	}
	if (arg[exit.arg +1])
	{
		ft_puterr("msh: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	exit.byte = (uint8_t)ft_atoi(arg[exit.arg]);
	ft_putstr("exit\n");
	msh_quit(exit.byte, env, gc);
}
