/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:05:29 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/10 12:19:17 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

t_env	*env_sort(t_env *env)
{
	t_env	env_sorted;

	if (!env)
		return (dbg_nullarg(__func__), NULL);
	env_sorted = env_lstdup(env);
	if ()
}