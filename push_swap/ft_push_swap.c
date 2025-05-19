/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:19:39 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/19 16:13:49 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

static void	display_list(t_list *list_a, t_list *list_b)
{
	while (list_a != NULL)
	{
		ft_printf("%d", list_a->data);
		if (list_b != NULL)
		{
			ft_printf(" %d\n", list_b->data);
			list_b = list_b->next;
		}
		else
			ft_printf("\n");
		list_a = list_a->next;
	}
	ft_printf("_ _\na b\n");
}

// static int	*set_index(int size, t_list **list)
// {
// 	t_list	*current;
// 	int		*tab;
// 	int		i;

// 	tab = malloc((sizeof(char)) * size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		current = (*list);
// 		while (current != NULL)
// 		{
// 			if (tab[i] >= current->data)
// 				tab[i] = current->data;
// 			current = current->next;
// 		}
// 		i++;
// 	}
// }

static t_list	*get_input(t_list **list, char *tab[], int i)
{
	t_list	*current;
	int		data;
	int		j;

	j = 1;
	data = ft_atoi(tab[j]);
	*list = ft_new_node(data);
	current = *list;
	while (j++ < i)
	{
		data = ft_atoi(tab[j]);
		current = ft_new_node(data);
		ft_lstadd_back(list, current);
	}
	current->next = NULL;
	return (*list);
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
	{
		ft_printf("Error !\n");
		return (1);
	}
	list_b = NULL;
	list_a = get_input(&list_a, argv, argc - 1);
	sort(&list_a, &list_b);
	display_list(list_a, list_b);
	return (0);
}
