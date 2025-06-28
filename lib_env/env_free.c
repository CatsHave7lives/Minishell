/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:58:44 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/28 11:01:56 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

void	env_free(t_env *env_node)
{
	t_env	*env_temp;

	while (env_node)
	{
		env_temp = env_node;
		env_node = env_node->next;
		free(env_temp->value);
		free(env_temp->variable);
		free(env_temp);
	}
}
