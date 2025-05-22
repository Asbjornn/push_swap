/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:33:50 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/22 11:37:21 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_list(t_list *list)
{
	int	i;

	i = list->data;
	while (list != NULL)
	{
		if (i != list->data)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_list_sorted(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->index != i)
			return (0);
		i++;
		list = list->next;
	}
	return (1);
}