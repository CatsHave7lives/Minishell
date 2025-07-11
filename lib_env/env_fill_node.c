/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fill_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:58:46 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/09 05:06:50 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

t_env	*env_fill_node(t_env *env_node, char *variable, char *value)
{
	if (!env_node || !variable)
		return (dbg_nullarg(__func__), NULL);
	env_node->variable = ft_strdup(variable);
	if (!env_node->variable)
		return (NULL);
	if (value)
	{
		env_node->value = ft_strdup(value);
		if (!env_node->value)
		{
			ft_free((void **)&env_node->variable);
			return (NULL);
		}
	}
	else
		env_node->value = NULL;
	env_node->next = NULL;
	return (env_node);
}
