/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:59 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/26 14:51:13 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	wheel_sort(t_list **list_a, t_list **list_b, int min, int max)
{
	int	j;

	j = min;
	while (j <= max)
	{
		while ((*list_a)->index > max || (*list_a)->index < min)
			ft_ra(list_a);
		ft_pb(list_a, list_b);
		j++;
	}
}

static int	find(t_list *list, int i)
{
	int	pos;

	pos = 0;
	while (list)
	{
		if (list->index == i)
			return (pos);
		pos ++;
		list = list->next;
	}
	return (-1);
}

static void	double_push(t_list **list_a, t_list **list_b, int i)
{
	int	pos;
	int	half_size;

	ft_pa(list_b, list_a);
	pos = find((*list_b), i);
	half_size = ft_lstsize((*list_b)) / 2;
	while ((*list_b)->index != i)
	{
		if (pos >= half_size)
			ft_rrb(list_b);
		else
			ft_rb(list_b);
	}
	ft_pa(list_b, list_a);
	ft_sa(list_a);
}

static void	wheel_sort_b(t_list **list_a, t_list **list_b)
{
	int	pos;
	int	half_size;
	int	i;

	i = ft_lstsize((*list_b)) - 1;
	while ((*list_b))
	{
		pos = find((*list_b), i);
		half_size = ft_lstsize((*list_b)) / 2;
		while ((*list_b)->index != i && (*list_b)->index != i - 1)
		{
			if (pos >= half_size)
				ft_rrb(list_b);
			else
				ft_rb(list_b);
		}
		if ((*list_b)->index == i)
			ft_pa(list_b, list_a);
		else
		{
			double_push(list_a, list_b, i);
			i--;
		}
		i--;
	}
}

void	chunk_sort(t_list **list_a, t_list **list_b)
{
	int	max;
	int	min;
	int	i;
	int	nbr_chunk;
	int	size;

	i = 0;
	size = ft_lstsize((*list_a));
	nbr_chunk = 5;
	while (i < nbr_chunk)
	{
		min = i * (size / nbr_chunk);
		if (i == nbr_chunk - 1)
			max = size - 1;
		else
			max = min + (size / nbr_chunk) - 1;
		wheel_sort(list_a, list_b, min, max);
		i++;
	}
	wheel_sort_b(list_a, list_b);
}
