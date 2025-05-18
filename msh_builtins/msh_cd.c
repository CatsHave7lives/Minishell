/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:04 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/18 15:36:24 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

typedef struct s_cd //msh_builtins.h
{
	char	*old_pwd;
	char	*new_pwd;
}			t_cd;

int	msh_cd(t_list *av, t_list **env)
{
	t_cd	cd;

	if (!av || !av->str)
		return (ft_putchar('\n'), EXIT_SUCCESS);
	if (!av->str[0])
		return (cd_home(*env));
	if (getcwd(NULL, 0) == NULL)
		return (msh_perror("cd"), errno);
	if (msh_cmd_is_one())// todo
		return (cd_execute(av, cd.pwd));// todo
	return (cd_error());// todo
}

int	cd_home(t_list *env)
{
	if (msh_get_from_env(env, "HOME"))
}

int	cd_execute(t_list *av, char *pwd322)
{
	char	*arg;
}
