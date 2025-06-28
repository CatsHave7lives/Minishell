/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:33 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/28 14:27:19 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

int	msh_pwd(t_gc **gc)
{
	char	*pwd;

	pwd = gc_getcwd(gc);
	if (!pwd)
		return (msh_perror("pwd"), EXIT_FAILURE);
	ft_putstr(pwd);
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}
