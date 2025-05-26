/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:59 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/26 09:26:46 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// static int	find_in_chunk(t_list *list_a, int min, int max)
// {
// 	int	pos;

// 	pos = 0;
// 	while (list_a)
// 	{
// 		if (list_a->index >= min && list_a->index <= max)
// 			return (pos);
// 		pos ++;
// 		list_a = list_a->next;
// 	}
// 	return (-1);
// }

static void	wheel_sort(t_list **list_a, t_list **list_b, int min, int max)
{
	// int	pos;
	// int	half_size;
	int	j;

	j = min;
	while (j <= max)
	{
		// pos = find_in_chunk((*list_a), min, max);
		// half_size = ft_lstsize((*list_a)) / 2;
		// if (!(*list_a)->next || pos == -1)
		// 	break ;
		while ((*list_a)->index > max || (*list_a)->index < min/* && (*list_a)->index != j + 1*/)
		{
			// if (pos >= half_size)
			// 	ft_rra(list_a);
			// else
				ft_ra(list_a);
		}
		ft_pb(list_a, list_b);
		/*if ((*list_a)->index == j)
			ft_pb(list_a, list_b);
		else
		{
			ft_pb(list_a, list_b);
			while ((*list_a)->index != j)
			{
				if (pos >= half_size)
					ft_rra(list_a);
				else
					ft_ra(list_a);
			}
			ft_pb(list_a, list_b);
			ft_sb(list_b);
			j++;
		}*/
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
