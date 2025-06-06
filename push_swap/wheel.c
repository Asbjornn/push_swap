/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:15:18 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/06 15:38:38 by gcauchy          ###   ########.fr       */
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

// static int	find(t_list *list_a, int i)
// {
// 	int	pos;

// 	pos = 0;
// 	while (list_a)
// 	{
// 		if (list_a->index == i)
// 			return (pos);
// 		pos ++;
// 		list_a = list_a->next;
// 	}
// 	return (-1);
// }

// void	wheel_sort(t_list **list_a, t_list **list_b)
// {
// 	int	pos;
// 	int	half_size;
// 	int	i;
// 	int	j;

// 	i = ft_lstsize((*list_a));
// 	j = 0;
// 	while (j < i)
// 	{
// 		pos = find((*list_a), j);
// 		half_size = ft_lstsize((*list_a)) / 2;
// 		if (!(*list_a)->next || pos == -1)
// 			break ;
// 		while ((*list_a)->index != j && (*list_a)->index != j + 1)
// 		{
// 			if (pos >= half_size)
// 				ft_rra(list_a);
// 			else
// 				ft_ra(list_a);
// 		}
// 		if ((*list_a)->index == j)
// 			ft_pb(list_a, list_b);
// 		else
// 		{
// 			ft_pb(list_a, list_b);
// 			while ((*list_a)->index != j)
// 			{
// 				if (pos >= half_size)
// 					ft_rra(list_a);
// 				else
// 					ft_ra(list_a);
// 			}
// 			ft_pb(list_a, list_b);
// 			ft_sb(list_b);
// 			j++;
// 		}
// 		j++;
// 	}
// 	while ((*list_b))
// 		ft_pa(list_b, list_a);
// }

// void	wheel_sort(t_list **list_a, t_list **list_b)
// {
// 	int	pos;
// 	int	half_size;
// 	int	i;
// 	int	j;
// 	int	p;

// 	j = 0;
// 	i = ft_lstsize((*list_a));
// 	while ((*list_a))
// 	{
// 		p = 0;
// 		while (p <= i)
// 		{
// 			if ((*list_a)->index < i / 2)
// 				ft_pb(list_a, list_b);
// 			else
// 			{
// 				ft_pb(list_a, list_b);
// 				ft_rb(list_b);
// 			}
// 			p++;
// 		}
// 		i /= 2;
// 	}
// 	i = ft_lstsize((*list_b));
// 	while (j <= i)
// 	{
// 		pos = find((*list_b), (i - j - 1));
// 		half_size = ft_lstsize((*list_b)) / 2;
// 		if (!(*list_b)->next || pos == -1)
// 			break ;
// 		while ((*list_b)->index != (i - j - 1)
// 			&& (*list_b)->index != (i - j - 1) - 1)
// 		{
// 			if (pos >= half_size)
// 				ft_rrb(list_b);
// 			else
// 				ft_rb(list_b);
// 		}
// 		if ((*list_b)->index == (i - j - 1))
// 			ft_pa(list_b, list_a);
// 		else
// 		{
// 			ft_pa(list_b, list_a);
// 			while ((*list_b)->index != (i - j - 1))
// 			{
// 				if (pos >= half_size)
// 					ft_rrb(list_b);
// 				else
// 					ft_rb(list_b);
// 			}
// 			ft_pa(list_b, list_a);
// 			ft_sa(list_a);
// 			j++;
// 		}
// 		j++;
// 	}
// }
