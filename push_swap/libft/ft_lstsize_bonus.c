/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:39:59 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/06 15:34:59 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_b(t_list_ *lst)
{
	t_list_	*current;
	int		size;

	current = lst;
	size = 0;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}
