/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bitwise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:51:22 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/09 20:27:50 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                           CHECK IS SORTED                                */
/*              go through the stack to check if is sorted                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                              GET MAX BIT                                 */
/*          take the biggest index and count how many bit it has            */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                            RADIX BITWISE ALGO                            */
/*                  compare the bit and push on b if it's 0                 */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

/*
RADIX BITWISE
Si le bit est a 0, je pb
Si le bit est a 1, je ra
puis je pa tout le reste
*/
