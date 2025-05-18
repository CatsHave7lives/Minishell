/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:04 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/18 23:07:28 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

typedef struct s_cd //msh_builtins.h
{
	char	*cur_dir;
	char	*new_dir;
	char	*home_check;
}			t_cd;

int	msh_cd(t_list *av, t_env **env)
{
	t_cd	cd;

	cd.cur_dir = getcwd(NULL, 0);
	if (!cd.cur_dir)
		return (msh_perror("cd"), EXIT_FAILURE);
	if (!av || !av->str || !av->str[0])
	{
		cd.home_check = cd_home(*env);
		if (cd.home_check == EXIT_FAILURE)
			return (free(cd.cur_dir), EXIT_FAILURE);
		cd.new_dir = getcwd(NULL, 0);
		if (!cd.new_dir)
			return (free(cd.cur_dir), msh_perror("cd"), EXIT_FAILURE);
		return (free(cd.new_dir), free(cd.cur_dir), EXIT_SUCCESS);
	}
	return (free(cd.cur_dir), EXIT_FAILURE)
	if (msh_cmd_is_one())// todo
		return (cd_execute(av, cd.old_pwd));// todo
	return (cd_error());// todo
}

int	cd_home(t_env *env)
{
	char	*home_path;

	home_path = msh_get_env_value(env, "HOME");
	if (!home_path)
		return (ft_puterr("msh: cd: HOME not set\n"), EXIT_FAILURE);
	if (chdir(home_path) == -1)
		return (msh_perror("cd"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	cd_execute(t_list *av, char *pwd322)
{
	char	*arg ;
}
