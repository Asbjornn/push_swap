/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bitwise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:51:22 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/19 15:55:01 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	max_bit(t_list *list)
{
	int	max;
	int	limit;

	max = 0;
	limit = 0;
	while (list != NULL)
	{
		if (max < list->data)
			max = list->data;
		list = list->next;
	}
	ft_printf("max%d\n", max);
	while (max > 0)
	{
		limit++;
		max = max >> 1;
	}
	return (limit);
}

void	radix_bitwise(t_list **list_a, t_list **list_b)
{
	int	limit;
	int	size;
	int	j;
	int	i;

	limit = max_bit((*list_a));
	i = 0;
	size = ft_lstsize((*list_a));
	while (i < limit)
	{
		j = 0;
		while (j < size)
		{
			if (((*list_a)->index >> i) & 1)
				ft_ra(list_a);
			else
				ft_pb(list_a, list_b);
			j++;
		}
		while ((*list_b) != NULL)
			ft_pa(list_b, list_a);
		i++;
	}
}

/*
RADIX BITWISE
Si le bit est a 1, je ra
Si le bit est a 0, je pb
puis je pa 
*/