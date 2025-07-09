/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:33 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/09 06:28:49 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

int	msh_pwd(t_gc **gc)
{
	char	*pwd;

	pwd = gc_getcwd(gc);
	if (!pwd)
	{
		msh_perror("pwd");
		return (EXIT_FAILURE);
	}
	ft_putstr(pwd);
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}
