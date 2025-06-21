/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:10:15 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/21 14:51:21 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

static t_env	*env_content(t_env *env_node, char *variable, char *value)
{
	env_node->variable = ft_strdup(variable);
	if (!env_node->variable) // start here
}

t_env	*env_malloc(t_env **env, char *variable, char *value)
{
	t_env	*env_node;

	if (!env)
		return (NULL);
	if (!*env)
	{
		*env = malloc(sizeof(t_env));
		if (!*env)
			return (NULL);
		env_node = *env;
	}
	else
	{
		env_node = *env;
		while (env_node->next)
			env_node = env_node->next;
		env_node->next = malloc(sizeof(t_env));
		if (!env_node->next)
			return (NULL);
		env_node = env_node->next;
	}
	return (env_content(env_node, variable, value));
}
