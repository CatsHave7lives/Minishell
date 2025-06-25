/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_msh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:59 by aessaber          #+#    #+#             */
/*   Updated: 2025/06/24 18:22:52 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MSH_H
# define LIB_MSH_H

# include "minishell.h"

void	msh_free_null(char **str);
void	*msh_null_guard(void *ptr, t_env **env, t_gc **gc);
void	msh_perror(char *cmd_name);

#endif