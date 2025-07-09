/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:38:41 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/09 06:16:18 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

t_env	*env_set_node(t_env **env, char *target_var, char *new_value, t_gc **gc)
{
	t_env	*env_node;
	char	*og_value;

	if (!env || !target_var || !gc)
		return (dbg_nullarg(__func__), NULL);
	env_node = env_get_node(env, target_var);
	if (env_node)
	{
		og_value = env_node->value;
		env_node->value = msh_null_guard(ft_strdup(new_value), env, gc);
		ft_free((void **)&og_value);
		return (env_node);
	}
	else
	{
		env_node = msh_null_guard(env_malloc(env), env, gc);
		env_node = msh_null_guard(env_fill_node(
					env_node, target_var, new_value), env, gc);
		return (env_node);
	}
}
