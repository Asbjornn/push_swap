/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:59 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/19 15:49:32 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	max_number(t_list *list)
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
		max /= 10;
		limit++;
	}
	return (limit);
}

void	chunk_sort(t_list **list_a, t_list **list_b)
{
	int	max;
	int	temp;
	int	i;
	int	j;
	int	h;

	i = 0;
	h = 10;
	max = max_number((*list_a));
	while (i < max)
	{
		j = 0;
		while (j < 10)
		{
			temp = (*list_a)->data;
			if (temp % h)
				ft_pb(list_a, list_b);
			else
				ft_ra(list_a);
			j++;
		}
		while ((*list_b))
			ft_pa(list_b, list_a);
		h *= 10;
		i++;
	}
}
