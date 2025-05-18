/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_env_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:38:41 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/18 17:30:01 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_library.h"

char	*msh_get_env_value(t_env *env, char *variable)
{
	if (!env)
		return (NULL);
	while (env)
	{
		if (!ft_strcmp(env->variable, variable))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
