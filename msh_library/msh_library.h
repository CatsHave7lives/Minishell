/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_library.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:59 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/18 17:30:11 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_LIBRARY_H
# define MSH_LIBRARY_H

# include "minishell.h"

void	msh_perror(char *cmd_name);
char	*msh_get_env_value(t_env *env, char *variable);

#endif