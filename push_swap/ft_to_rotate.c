/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:44:24 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/09 20:26:11 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                  ROTATE                                  */
/*                      first element become the last                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static	void	ft_rotate(t_list **src)
{
	t_list	*last;

	last = ft_lstlast(*src);
	last->next = (*src);
	(*src)->previous = last;
	(*src) = (*src)->next;
	(*src)->previous = NULL;
	last->next->next = NULL;
}

void	ft_ra(t_list **list_a)
{
	ft_rotate(list_a);
	ft_printf("ra\n");
}

void	ft_rb(t_list **list_b)
{
	ft_rotate(list_b);
	ft_printf("rb\n");
}

void	ft_rr(t_list **list_a, t_list **list_b)
{
	ft_rotate(list_a);
	ft_rotate(list_b);
	ft_printf("rr\n");
}
