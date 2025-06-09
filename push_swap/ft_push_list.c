/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:35:01 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/09 20:23:55 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                              PUSH FUNTION                                */
/*                  push the top of the stack on the top other              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static	void	ft_push(t_list **src, t_list **dest)
{
	t_list	*current;

	current = *src;
	if ((*src)->next != NULL)
	{
		(*src) = (*src)->next;
		(*src)->previous = NULL;
	}
	else
		(*src) = NULL;
	if (!(*dest))
	{
		(*dest) = current;
		(*dest)->next = NULL;
		(*dest)->previous = NULL;
	}
	else
		ft_lstadd_front(dest, current);
}

void	ft_pa(t_list **src, t_list **dest)
{
	if (!*src)
		return ;
	ft_push(src, dest);
	ft_printf("pa\n");
}

void	ft_pb(t_list **src, t_list **dest)
{
	if (!*src)
		return ;
	ft_push(src, dest);
	ft_printf("pb\n");
}
