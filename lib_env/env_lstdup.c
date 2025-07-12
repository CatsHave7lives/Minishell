/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 08:49:35 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 12:08:17 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

t_env	*env_lstdup(t_env **env, t_gc **gc)
{
	t_env	*env_node;
	t_env	*dup_head;
	t_env	*dup_node;
	t_env	*dup_last;

	env_node = *env;
	dup_head = NULL;
	dup_node = NULL;
	dup_last = NULL;
	while (env_node)
	{
		dup_node = malloc(sizeof (t_env));
		if (!dup_node)
			return (env_free(&dup_head), NULL);
		ft_memset(dup_node, 0, sizeof(t_env));
		if (!env_fill_node(dup_node, env_node->variable, env_node->value))
			return (ft_free(dup_node), env_free(&dup_head), NULL);
		if (!dup_head)
			dup_head = dup_node;
		else
			dup_last->next = dup_node;
		dup_last = dup_node;
		env_node = env_node->next;
	}
	return (dup_head);
}
