/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_constant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:15:39 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/04 02:51:31 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ms_arg_is_constant(char *str, char constant, size_t start)
{
	while (str[start])
	{
		if (str[start] != constant)
			return (false);
		start++;
	}
	return (true);
}
