/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bitwise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:51:22 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/25 12:27:00 by gcauchy          ###   ########.fr       */
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

static int	max_bit(t_list *list)
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
		if (is_sorted((*list_a)))
			break ;
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

// static void    radix_bucket_bitwise(t_list **list_a, t_list ** list_b)
// {
//     int limit;
// 	int	size;
//     int i;
// 	int	j;
    
//     limit = max_bit((*list_b));
// 	i = 0;
// 	while (i < limit)
// 	{
// 		size = ft_lstsize((*list_b));
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (((*list_b)->index >> i) & 1)
// 				ft_rb(list_b);
// 			else
// 				ft_pa(list_b, list_a);
// 			j++;
// 		}
// 		while(ft_lstsize((*list_b)) < size)
// 			ft_pb(list_a, list_b);
// 		i++;
// 	}
// 	while ((*list_b))
// 		ft_pa(list_b, list_a);
// }

// void	ultra_bucket_radix(t_list **list_a, t_list **list_b)
// {
// 	int	bucket_size;
// 	int	i;

// 	bucket_size = 3;
// 	i = 0;
// 	while (bucket_size >= i)
// 	{
// 		push_bucket(list_a, list_b, bucket_size);
// 		radix_bucket_bitwise(list_a, list_b);
// 		bucket_size--;
// 	}	
// }

/*
RADIX BITWISE
Si le bit est a 1, je ra
Si le bit est a 0, je pb
puis je pa tout le reste
*/
