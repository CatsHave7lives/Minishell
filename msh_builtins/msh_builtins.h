/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtins.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:03:25 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/25 13:07:16 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTINS_H
# define MSH_BUILTINS_H

# include "minishell.h"

typedef struct s_echo
{
	bool	flag_n;
	bool	is_not_first;
}	t_echo;

typedef struct s_cd
{
	char	*old_pwd;
	char	*new_pwd;
}	t_cd;

int		msh_echo(t_list *arg);

#endif