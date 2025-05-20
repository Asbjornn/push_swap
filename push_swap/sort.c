/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:29:46 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/20 16:06:53 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	check_list(t_list *list)
{
	int	i;

	i = list->data;
	while (list != NULL)
	{
		if (i != list->data)
			return (0);
		list = list->next;
	}
	return (1);
}

void	sort3(t_list **list)
{
	t_list	*second;
	t_list	*third;

	second = (*list)->next;
	third = second->next;
	if (check_list((*list)))
		return ;
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

	if (check_list((*list_a)))
		return ;
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

	if (check_list((*list_a)))
		return ;
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
	int		index;

	index = ft_lstsize((*list_a));
	ft_printf("index = %d\n", index);
	if (index == 2)
	{
		if ((*list_a)->data > (*list_a)->next->data)
			ft_sa(list_a);
		return ;
	}
	else if (index == 3)
		sort3(list_a);
	else if (index == 4)
		sort4(list_a, list_b);
	else if (index == 5)
		sort5(list_a, list_b);
	else
		wheel_sort(list_a, list_b);
		//radix_bitwise(list_a, list_b);
		//chunk_sort(list_a, list_b);
}
