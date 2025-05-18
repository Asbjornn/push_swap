/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:19:39 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/16 22:11:02 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

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
	t_list	*current_a;
	t_list	*current_b;

	if (argc < 2)
	{
		ft_printf("Error !\n");
		return (1);
	}
	list_b = NULL;
	list_a = get_input(&list_a, argv, argc - 1);
	sort(&list_a, &list_b);
	current_a = list_a;
	current_b = list_b;
	while (current_a != NULL)
	{
		ft_printf("%d", current_a->data);
		if (current_b != NULL)
		{
			ft_printf(" %d\n", current_b->data);
			current_b = current_b->next;
		}
		else
			ft_printf("\n");
		current_a = current_a->next;
	}
	ft_printf("_ _\na b\n");
	// ft_printf("\nafter rotate\n\n");
	// ft_ra(&list_a);
	// current_a = list_a;
	// while (current_a != NULL)
	// {
	// 	//ft_printf("|----------------  list n.%d  ---------------|\n", i);
	// 	ft_printf("%d\n", current_a->data);
	// 	//ft_printf("next data     :%d\n", list_a->next->data);
	// 	// if (current_a->previous != NULL)
	// 	// 	ft_printf("previous data :%d\n", current_a->previous->data);
	// 	current_a = current_a->next;
	// }
	// ft_printf("_\na\n");
	// ft_printf("\nafter reverse rotate\n\n");
	// ft_rra(&list_a);
	// current_a = list_a;
	// while (current_a != NULL)
	// {
	// 	//ft_printf("|----------------  list n.%d  ---------------|\n", i);
	// 	ft_printf("%d\n", current_a->data);
	// 	//ft_printf("next data     :%d\n", current_a->next->data);
	// 	// if (current_a->previous != NULL)
	// 	// 	ft_printf("previous data :%d\n", current_a->previous->data);
	// 	current_a = current_a->next;
	// }
	// ft_printf("_\na\n");
	// ft_printf("\nafter push b\n\n");
	// ft_pb(&list_a, &list_b);
	// ft_pb(&list_a, &list_b);
	// current_a = list_a;
	// current_b = list_b;
	// while (current_a != NULL)
	// {
	// 	//ft_printf("|----------------  list n.%d  ---------------|\n", i);
	// 	ft_printf("%d", current_a->data);
	// 	// if (current_a->next != NULL)
	// 	// 	ft_printf(" : next data : %d", current_a->next->data);
	// 	// if (current_a->previous != NULL)
	// 	// 	ft_printf(" : previous data : %d", current_a->previous->data);
	// 	if (current_b != NULL)
	// 	{
	// 		ft_printf(" %d\n", current_b->data);
	// 		current_b = current_b->next;
	// 	}
	// 	else
	// 		ft_printf("\n");
	// 	current_a = current_a->next;
	// }
	// ft_printf("_ _\na b\n");
	// ft_printf("\nafter push a\n\n");
	// ft_ss(&list_a, &list_b);
	// current_a = list_a;
	// current_b = list_b;
	// while (current_a != NULL)
	// {
	// 	//ft_printf("|----------------  list n.%d  ---------------|\n", i);
	// 	ft_printf("%d", current_a->data);
	// 	// if (current_a->next != NULL)
	// 	// 	ft_printf(" : next data : %d", current_a->next->data);
	// 	// if (current_a->previous != NULL)
	// 	// 	ft_printf(" : previous data : %d", current_a->previous->data);
	// 	if (current_b != NULL)
	// 	{
	// 		ft_printf(" %d\n", current_b->data);
	// 		current_b = current_b->next;
	// 	}
	// 	else
	// 		ft_printf("\n");
	// 	current_a = current_a->next;
	// }
	// ft_printf("_ _\na b\n");
	return (0);
}
