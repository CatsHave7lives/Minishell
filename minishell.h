/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:42 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/17 13:39:23 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>

# include "lib_env.h"
# include "lib_ft.h"
# include "lib_gc.h"
# include "lib_msh.h"
# include "msh_builtins.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_env
{
	char			*variable;
	char			*value;
	struct s_env	*next;
}	t_env;

#endif
/* Rules:
- Funcitons made specifically for minishell should start with "msh_"
- Garbage collector functions should start "gc_"
- Other functions that are useful outside minishell should start with "ft_"
*/