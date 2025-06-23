/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:51:26 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/22 10:00:47 by aessaber         ###   ########.fr       */
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

t_env	*env_get_node(t_env **env, char *target_variable);
int		env_set_node_value(t_env **env, char *target_variable, char *new_value);
t_env	*env_add_node(t_env **env);

#endif