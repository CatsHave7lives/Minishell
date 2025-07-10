/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtins.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:03:25 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/10 09:04:51 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTINS_H
# define MSH_BUILTINS_H

# include "minishell.h"

typedef struct s_echo
{
	int		row;
	bool	flag_n;
	bool	is_not_first;
}	t_echo;

typedef struct s_cd
{
	char	*old_pwd;
	char	*new_pwd;
}	t_cd;

int	msh_cd(const char **arg, t_env **env, t_gc **gc);
int	msh_echo(const char **arg);
int	msh_env(t_env *env);

#endif