/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:42:42 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/05 04:41:16 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define FD_OP 1
# define SUCCESS 0

typedef struct s_arg
{
	char			*str;
	struct s_arg	*next;
}					t_arg;

void	ft_putchar(char c);
void	ft_putstr(char *str);

int		msh_echo(t_arg *arg);

bool	msh_arg_is_constant(char *str, char constant, size_t start);

#endif