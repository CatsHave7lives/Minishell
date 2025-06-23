/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:10:15 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/23 17:39:45 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

t_env	*env_malloc(t_env **env)
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
	ft_memset(env_node, 0, sizeof(t_env));
	return (env_node);
}
