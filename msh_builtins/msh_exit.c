/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:28 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/09 04:23:22 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

static void	exit_program(int status, t_env **env, t_gc **gc)
{
	env_free(env);
	gc_free(gc);
	exit(status);
}

int	msh_exit(t_list *arg, int status, t_env **env, t_gc **gc)
{
	uint8_t	byte;

	if (!env || !gc)
		return (dbg_nullarg(__func__), EXIT_FAILURE);
	if (!arg || !arg->str)
	{
		ft_putstr("exit\n");
		exit_program(status, env, gc);
	}
	if (!ft_str_is_number(arg->str))
	{
		ft_puterr("msh: exit: ");
		ft_puterr(arg->str);
		ft_puterr(": numeric argument required\n");
		exit_program(UINT8_MAX, env, gc);
	}
	if (arg->next)
	{
		ft_puterr("msh: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	byte = ft_atoi(arg->str);
	ft_putstr("exit\n");
	exit_program(byte, env, gc);
}
