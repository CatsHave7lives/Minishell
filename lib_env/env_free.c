/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:58:44 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 12:01:31 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

void	env_free(t_env **env_head)
{
	t_env	*env_node;
	t_env	*env_temp;

	env_node = *env_head;
	while (env_node)
	{
		env_temp = env_node;
		env_node = env_node->next;
		ft_free((void **)&env_temp->value);
		ft_free((void **)&env_temp->variable);
		ft_free((void **)&env_temp);
	}
	*env_head = NULL;
}
