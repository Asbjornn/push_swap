/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:45:31 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/06 15:22:04 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_b(t_list_ **lst, void (*del)(void*))
{
	t_list_	*current;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		current = *lst;
		*lst = current->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
