/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:49:40 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/19 15:56:15 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_new_node(int data)
{
	t_list	*current;

	current = malloc(sizeof (t_list));
	if (!current)
		return (NULL);
	current->data = data;
	current->index = 0;
	current->next = NULL;
	current->previous = NULL;
	return (current);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	new->next->previous = new;
	new->previous = NULL;
	(*lst) = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->previous = current;
}

int	ft_lstsize(t_list *list)
{
	t_list	*current;
	int		size;

	size = 0;
	current = list;
	while (current != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}
