/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:14:27 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/15 13:55:34 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	void	swap(t_list **list)
{
	int	temp;

	temp = (*list)->next->data;
	(*list)->next->data = (*list)->data;
	(*list)->data = temp;

	// t_list	*current;
	
	// current = (*list)->next;
	// (*list)->next = current->next;
	// (*list)->next->previous = (*list);
	// current->next = (*list);
	// current->previous = NULL;
	// (*list) = current;
}

void	ft_sa(t_list **list_a)
{
	if ((*list_a)->next == NULL || !list_a)
		return ;
	swap(list_a);
	ft_printf("sa\n");
}

void	ft_sb(t_list **list_b)
{
	if ((*list_b)->next == NULL || !list_b)
		return ;
	swap(list_b);
	ft_printf("sb\n");
}

void	ft_ss(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}
