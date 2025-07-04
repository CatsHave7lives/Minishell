/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:04 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/29 15:20:40 by aessaber         ###   ########.fr       */
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
		return (msh_free_null(&cd->old_pwd), EXIT_FAILURE);
	}
	if (chdir(env_node_home->value) == -1)
		return (msh_perror("cd"), msh_free_null(&cd->old_pwd), EXIT_FAILURE);
	cd->new_pwd = gc_getcwd(gc);
	if (!cd->new_pwd)
		return (msh_perror("cd"), msh_free_null(&cd->old_pwd), EXIT_FAILURE);
	if (env_set_node(env, "OLDPWD", cd->old_pwd, gc) == NULL
		|| env_set_node(env, "PWD", cd->new_pwd, gc) == NULL)
		status = EXIT_FAILURE;
	msh_free_null(&cd->old_pwd);
	msh_free_null(&cd->new_pwd);
	return (status);
}

static int	cd_update_env(t_list *arg, t_cd *cd, t_env **env, t_gc **gc)
{
	int		status;

	status = EXIT_SUCCESS;
	if (chdir(arg->str) == -1)
		return (msh_perror("cd"), msh_free_null(&cd->old_pwd), EXIT_FAILURE);
	cd->new_pwd = gc_getcwd(gc);
	if (!cd->new_pwd)
		return (msh_perror("cd"), msh_free_null(&cd->old_pwd), EXIT_FAILURE);
	if (env_set_node(env, "OLDPWD", cd->old_pwd, gc) == NULL
		|| env_set_node(env, "PWD", cd->new_pwd, gc) == NULL)
		status = EXIT_FAILURE;
	msh_free_null(&cd->old_pwd);
	msh_free_null(&cd->new_pwd);
	return (status);
}

int	msh_cd(t_list *arg, t_env **env, t_gc **gc)
{
	t_cd	cd;

	cd.old_pwd = gc_getcwd(gc);
	if (!cd.old_pwd)
		return (msh_perror("cd"), EXIT_FAILURE);
	if (!arg || !arg->str)
		return (cd_home(&cd, env, gc));
	if (!arg->str[0])
		return (msh_free_null(&cd.old_pwd), EXIT_SUCCESS);
	else
		return (cd_update_env(arg, &cd, env, gc));
}
