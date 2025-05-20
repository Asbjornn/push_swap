/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bitwise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:51:22 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/20 10:33:46 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	is_sorted(t_list *list)
{
	if (list->index != 0)
		return (0);
	while (list->next)
	{
		if ((list->index + 1) != list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}

/*tatic int	max_bit(t_list *list)
{
	int	max;
	int	limit;

	max = 0;
	limit = 0;
	while (list != NULL)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	ft_printf("max%d\n", max);
	while (max > 0)
	{
		limit++;
		max = max >> 1;
	}
	return (limit);
}*/

void	radix_bitwise(t_list **list_a, t_list **list_b)
{
	//int	limit;
	int	size;
	int	j;
	int	i;

	//limit = max_bit((*list_a));
	i = 0;
	size = ft_lstsize((*list_a));
	while (i < size)
	{
		if (is_sorted((*list_a)))
			break ;
		ft_printf("boucle : %d\n", i);
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