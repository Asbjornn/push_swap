/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:47:10 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/06 15:22:29 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_	*ft_lstnew_b(void *content)
{
	t_list_	*curent;

	curent = malloc(sizeof(t_list_));
	if (!curent)
		return (NULL);
	curent->content = content;
	curent->next = NULL;
	return (curent);
}
