/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_msh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:59 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/23 16:37:23 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MSH_H
# define LIB_MSH_H

# include "minishell.h"

void	msh_perror(char *cmd_name);
void	*msh_null_guard(void *ptr, t_env **env, t_gc **gc);

#endif