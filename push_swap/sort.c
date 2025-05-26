/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:29:46 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/26 14:55:04 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	is_list_sorted(t_list *list)
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

static void	sort3(t_list **list)
{
	t_list	*second;
	t_list	*third;

	second = (*list)->next;
	third = second->next;
	if ((*list)->data > second->data && (*list)->data <= third->data)
		ft_sa(list);
	else if ((*list)->data > second->data && second->data > third->data)
	{
		ft_ra(list);
		ft_sa(list);
	}
	else if ((*list)->data > second->data && second->data <= third->data)
		ft_ra(list);
	else if ((*list)->data < second->data && (*list)->data < third->data
		&& second->data > third->data)
	{
		ft_rra(list);
		ft_sa(list);
	}
	else if ((*list)->data < second->data && second->data > third->data)
		ft_rra(list);
}

static void	sort4(t_list **list_a, t_list **list_b)
{
	t_list	*current;
	int		small;

	small = (*list_a)->data;
	current = (*list_a);
	while (current != NULL)
	{
		if (small > current->data)
			small = current->data;
		current = current->next;
	}
	if (small >= ft_lstlast((*list_a))->data)
		ft_rra(list_a);
	else
		while ((*list_a)->data != small)
			ft_ra(list_a);
	ft_pb(list_a, list_b);
	sort3(list_a);
	ft_pa(list_b, list_a);
}

static void	sort5(t_list **list_a, t_list **list_b)
{
	t_list	*current;
	int		small;

	small = (*list_a)->data;
	current = (*list_a);
	while (current != NULL)
	{
		if (small > current->data)
			small = current->data;
		current = current->next;
	}
	if (small >= ft_lstlast((*list_a))->data
		|| small >= ft_lstlast(*list_a)->previous->data)
		while ((*list_a)->data != small)
			ft_rra(list_a);
	else
		while ((*list_a)->data != small)
			ft_ra(list_a);
	ft_pb(list_a, list_b);
	sort4(list_a, list_b);
	ft_pa(list_b, list_a);
}

void	sort(t_list **list_a, t_list **list_b)
{
	int	size;

	if (is_list_sorted((*list_a)))
		return ;
	size = ft_lstsize((*list_a));
	if (size == 2)
		ft_sa(list_a);
	else if (size == 3)
		sort3(list_a);
	else if (size == 4)
		sort4(list_a, list_b);
	else if (size == 5)
		sort5(list_a, list_b);
	else if (size <= 100)
		chunk_sort(list_a, list_b);
	else
		radix_bitwise(list_a, list_b);
}
