/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:49:58 by aessaber          #+#    #+#             */
/*   Updated: 2025/05/07 11:05:37 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library.h"

int	ft_lstlen(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}