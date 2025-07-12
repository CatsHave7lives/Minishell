/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:05:29 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 08:50:13 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_env.h"

static void	static_sort(t_env *env_dup)
{
	t_env	*env_cur;
	bool	sorted;
	char	*tmp_variable;
	char	*tmp_value;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
		env_cur = env_dup;
		while (env_cur->next)
		{
			if (ft_strcmp(env_cur->variable, env_cur->next->variable) > 0)
			{
				sorted = false;
				tmp_variable = env_cur->variable;
				env_cur->variable = env_cur->next->variable;
				env_cur->next->variable = tmp_variable;
				tmp_value = env_cur->value;
				env_cur->value = env_cur->next->value;
				env_cur->next->value = tmp_value;
			}
			env_cur = env_cur->next;
		}
	}
}

t_env	*env_sort(t_env **env, t_gc **gc)
{
	t_env	*env_dup;

	if (!env || !*env)
		return (dbg_nullarg(__func__), NULL);
	env_dup = msh_null_guard((void *)env_lstdup(env), env, gc);
	static_sort(env_dup);
	return (env_dup);
}
