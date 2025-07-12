/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:30 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 15:50:04 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

static void	export_all(t_env **env, t_gc **gc)
{
	t_env	*env_sorted;
	t_env	*env_node;

	env_sorted = msh_null_guard((void *)env_sort(env, gc), env, gc);
	env_node = env_sorted;
	while (env_node)
	{
		ft_putstr("declare -x ");
		ft_putstr(env_node->variable);
		if (env_node->value)
		{
			ft_putstr("=\"");
			ft_putstr(env_node->value);
			ft_putchar('\"');
		}
		ft_putchar('\n');
		env_node = env_node->next;
	}
	env_free(&env_sorted);
}

static void	export_error(const char *arg)
{
	int	col;

	ft_puterr("msh: export: `");
	col = 0;
	while (arg[col] && arg[col] != '=')
		ft_putchar_err(arg[col]);
	ft_puterr("': not a valid identifier\n");
}

static char	*export_parsing(const char *arg)
{
	int	col;

	col = 0;
	if (!ft_isalpha(arg[col]) && arg[col] != '_')
		return (export_error(arg), NULL);
	while (arg[col] && (ft_isalnum(arg[col]) || arg[col] == '_'))
		col++;
	if (arg[col] && arg[col] != '=')
		return (export_error(arg), NULL);
	return ((char *)&arg[col]);
}

int	msh_export(const char **arg, t_env **env, t_gc **gc)
{
	t_export	export;

	export.arg = 1;
	if (!arg[export.arg])
		export_all(env, gc);
	while (arg[export.arg])
	{
		export_parsing(arg[export.arg]);
	}
}
