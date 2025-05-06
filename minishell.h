/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:42 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/06 06:14:06 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_arg
{
	char			*str;
	struct s_arg	*next;
}					t_arg;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterr(char *str);

int		msh_echo(t_arg *arg);

bool	msh_arg_is_constant(char *str, char constant, size_t start);
void	msh_perror(char *cmd_name);

#endif
/* Rules:
- 
*/