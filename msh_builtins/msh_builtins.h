/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtins.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:03:25 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 08:26:00 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTINS_H
# define MSH_BUILTINS_H

# include "minishell.h"

typedef struct s_echo
{
	int		arg;
	bool	flag_n;
	bool	is_not_first;
}	t_echo;

typedef struct s_cd
{
	int		arg;
	char	*old_pwd;
	char	*new_pwd;
}	t_cd;

typedef struct s_exit
{
	int		arg;
	uint8_t	byte;
}	t_exit;

typedef struct s_export
{
	int		arg;
}	t_export;

int	msh_cd(const char **arg, t_env **env, t_gc **gc);
int	msh_echo(const char **arg);
int	msh_env(t_env *env);

#endif