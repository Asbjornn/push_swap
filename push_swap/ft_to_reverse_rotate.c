/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:58:49 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/09 20:25:47 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                              REVERSE ROTATE                              */
/*                          last element become first                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static	void	ft_rotate_reverse(t_list **src)
{
	t_list	*last;

	last = ft_lstlast(*src);
	last->next = (*src);
	last->previous->next = NULL;
	last->previous = NULL;
	(*src)->previous = last;
	(*src) = last;
}

void	ft_rra(t_list **list_a)
{
	ft_rotate_reverse(list_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_list **list_b)
{
	ft_rotate_reverse(list_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **list_a, t_list **list_b)
{
	ft_rra(list_a);
	ft_rrb(list_b);
	ft_printf("rrr\n");
}
