/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_msh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:59 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/11 08:19:14 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MSH_H
# define LIB_MSH_H

# include "minishell.h"

void	*msh_null_guard(void *ptr, t_env **env, t_gc **gc);
void	msh_perror(char *cmd_name);
void	msh_quit(int status, t_env **env, t_gc **gc);

#endif