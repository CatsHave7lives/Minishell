/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:51:26 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 12:11:00 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_ENV_H
# define LIB_ENV_H

# include "minishell.h"

typedef struct s_env
{
	char			*variable;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*env_fill_node(t_env *env_node, char *variable, char *value);
void	env_free(t_env **env_node);
t_env	*env_get_node(t_env **env, char *target_variable);
t_env	*env_lstdup(t_env **env, t_gc **gc);
t_env	*env_malloc(t_env **env);
t_env	*env_set_node(
			t_env **env, char *target_var, char *new_value, t_gc **gc);
t_env	*env_sort(t_env **env, t_gc **gc);

#endif