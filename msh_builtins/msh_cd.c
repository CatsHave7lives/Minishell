/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:04 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 07:49:32 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

static int	cd_home(t_cd *cd, t_env **env, t_gc **gc)
{
	t_env	*env_node_home;

	env_node_home = env_get_node(env, "HOME");
	if (!env_node_home || !env_node_home->value)
	{
		ft_puterr("msh: cd: HOME not set\n");
		ft_free((void **)&cd->old_pwd);
		return (EXIT_FAILURE);
	}
	if (chdir(env_node_home->value) == -1)
		return (msh_perror("cd"), ft_free((void **)&cd->old_pwd), EXIT_FAILURE);
	cd->new_pwd = gc_getcwd(gc);
	if (!cd->new_pwd)
		return (msh_perror("cd"), ft_free((void **)&cd->old_pwd), EXIT_FAILURE);
	msh_null_guard(
		(void *)env_set_node(env, "OLDPWD", cd->old_pwd, gc), env, gc);
	msh_null_guard((void *)env_set_node(env, "PWD", cd->new_pwd, gc), env, gc);
	return (EXIT_SUCCESS);
}

static int	cd_update_env(const char **arg, t_cd *cd, t_env **env, t_gc **gc)
{
	if (chdir(arg[cd->arg]) == -1)
	{
		msh_perror("cd");
		return (EXIT_FAILURE);
	}
	cd->new_pwd = gc_getcwd(gc);
	if (!cd->new_pwd)
	{
		msh_perror("cd");
		return (EXIT_FAILURE);
	}
	msh_null_guard(
		(void *)env_set_node(env, "OLDPWD", cd->old_pwd, gc), env, gc);
	msh_null_guard((void *)env_set_node(env, "PWD", cd->new_pwd, gc), env, gc);
	return (EXIT_SUCCESS);
}

int	msh_cd(const char **arg, t_env **env, t_gc **gc)
{
	t_cd	cd;

	if (!arg || !env || !gc)
		return (dbg_nullarg(__func__), EXIT_FAILURE);
	cd.old_pwd = gc_getcwd(gc);
	if (!cd.old_pwd)
	{
		msh_perror("cd");
		return (EXIT_FAILURE);
	}
	cd.arg = 1;
	if (!arg || !arg[cd.arg])
		return (cd_home(&cd, env, gc));
	if (!arg[cd.arg][0])
		return (EXIT_SUCCESS);
	else
		return (cd_update_env(arg, &cd, env, gc));
}
