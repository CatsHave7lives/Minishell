/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:51:26 by aessaber          #+#    #+#             */
/*   Updated: 2025/07/12 15:39:10 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FT_H
# define LIB_FT_H

# include "minishell.h"

int		ft_atoi(const char *str);
void	ft_free(void **ptr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_lstlen(t_list *lst);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_err(char c);
void	ft_putchar(char c);
void	ft_puterr(const char *str);
void	ft_putstr(char *str);
bool	ft_str_is_mono(char *str, char constant, size_t start);
bool	ft_str_is_num(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t end);

#endif