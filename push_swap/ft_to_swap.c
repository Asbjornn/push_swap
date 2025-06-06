/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:14:27 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/06 15:29:21 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*									SWAP									*/
/*					swap the first two element on a stack					*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static	void	swap(t_list **list)
{
	int	temp;

	temp = (*list)->next->data;
	(*list)->next->data = (*list)->data;
	(*list)->data = temp;
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
