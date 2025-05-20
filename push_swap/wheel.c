/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:15:18 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/20 14:08:15 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// static int	max_(t_list *list)
// {
// 	int	max;

// 	max = 0;
// 	while (list != NULL)
// 	{
// 		if (list->index > max)
// 			max = list->index;
// 		list = list->next;
// 	}
// 	return (max);
// }

static int	find(t_list *list_a, int i)
{
	int	pos;

	pos = 0;
	while (list_a)
	{
		if (list_a->index == i)
			break ;
		pos ++;
		list_a = list_a->next;
	}
	return (pos);
}

void	wheel_sort(t_list **list_a, t_list **list_b)
{
	int	pos;
	int	size;
	int	i;
	int	j;

	i = ft_lstsize((*list_a));
	j = 0;
	while (j <= i)
	{
		pos = find((*list_a), j);
		size = ft_lstsize((*list_a)) / 2;
		if (!(*list_a)->next)
			break ;
		while ((*list_a)->index != j)
		{
			if (pos >= size)
				ft_rra(list_a);
			else
				ft_ra(list_a);
		}
		ft_pb(list_a, list_b);
		j++;
	}
	while ((*list_b))
		ft_pa(list_b, list_a);
}
