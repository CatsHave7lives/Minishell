/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:19 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/28 13:17:13 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gc.h"

int	msh_env(t_env *env)
{
	t_env	*node;

	node = env;
	while (node)
	{
		if (node->value)
		{
			ft_putstr(node->variable);
			ft_putchar('=');
			ft_putstr(node->value);
			ft_putchar('\n');
		}
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
