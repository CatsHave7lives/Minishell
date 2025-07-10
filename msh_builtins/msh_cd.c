/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:04 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/10 08:37:47 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

static int	cd_home(t_cd *cd, t_env **env, t_gc **gc)
{
	t_env	*env_node_home;
	int		status;

	status = EXIT_SUCCESS;
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
	if (env_set_node(env, "OLDPWD", cd->old_pwd, gc) == NULL
		|| env_set_node(env, "PWD", cd->new_pwd, gc) == NULL)
		status = EXIT_FAILURE;
	ft_free((void **)&cd->old_pwd);
	ft_free((void **)&cd->new_pwd);
	return (status);
}

static int	cd_update_env(const char **arg, t_cd *cd, t_env **env, t_gc **gc)
{
	int		status;

	status = EXIT_SUCCESS;
	if (chdir(arg[1]) == -1)
	{
		msh_perror("cd");
		ft_free((void **)&cd->old_pwd);
		return (EXIT_FAILURE);
	}
	cd->new_pwd = gc_getcwd(gc);
	if (!cd->new_pwd)
	{
		msh_perror("cd");
		ft_free((void **)&cd->old_pwd);
		return (EXIT_FAILURE);
	}
	if (env_set_node(env, "OLDPWD", cd->old_pwd, gc) == NULL
		|| env_set_node(env, "PWD", cd->new_pwd, gc) == NULL)
		status = EXIT_FAILURE;
	ft_free((void **)&cd->old_pwd);
	ft_free((void **)&cd->new_pwd);
	return (status);
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
	if (!arg || !arg[1])
		return (cd_home(&cd, env, gc));
	if (!arg[1][0])
	{
		ft_free((void **)&cd.old_pwd);
		return (EXIT_SUCCESS);
	}
	else
		return (cd_update_env(arg, &cd, env, gc));
}
