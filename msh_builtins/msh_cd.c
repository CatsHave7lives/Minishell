/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:04 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/16 12:02:29 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtins.h"

int	msh_cd(t_list *av, t_list *env)
{
	t_cd	cd;

	if (getcwd(NULL, 0) == NULL)
		return (msh_perror("cd"), errno);
	if (msh_cmd_is_one())// todo
		return (cd_execute(av, cd.pwd));// todo
	return (cd_error());// todo
}

static int	cd_execute(t_list *av, char *pwd)
{
	char	*arg;
	
}
