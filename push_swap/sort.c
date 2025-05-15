/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:29:46 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/15 14:50:21 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	else if ((*list)->data < second->data && second->data > third->data)
		ft_rra(list);
	else
		ft_printf("no.\n");
}

static void	sort5(t_list **list_a, t_list **list_b)
{
	t_list	*current;
	// int		index;
	int		small;

	current = (*list_a);
	small = current->data;
	// index = 0;
	while (current != NULL)
	{
		if (small < current->data)
		{
			small = current->data;
		}
	}
	ft_pb(list_a, list_b);
	sort3(list_a);
	ft_pa(list_b, list_a);
}

void	sort(t_list **list_a, t_list **list_b)
{
	t_list	*current;
	int		index;

	index = ft_lstsize(&list_a);
	if (index == 3)
		sort3(list_a);
	else if (index == 4 || index == 5)
		sort5(list_a, list_b);
}