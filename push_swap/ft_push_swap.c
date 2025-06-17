/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:19:39 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/17 10:11:02 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                              SPLIT ARGUMENT                              */
/*          if only 2 argv, split and fill the chained list with            */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static t_list	*split_it(t_list **list, char **argv)
{
	t_list	*current;
	char	**tmp_array;
	int		i;
	int		data;

	tmp_array = ft_split(argv[1], ' ');
	data = ft_atol(tmp_array[0]);
	*list = ft_new_node(data);
	current = *list;
	i = 1;
	while (tmp_array[i])
	{
		data = ft_atol(tmp_array[i]);
		current = ft_new_node(data);
		ft_lstadd_back(list, current);
		i++;
	}
	current->next = NULL;
	free_all(tmp_array);
	return (*list);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                  SET INDEX                               */
/*                      set the index of all the values                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void	set_index(t_list **list)
{
	t_list	*current;
	t_list	*current2;
	int		index;

	current = (*list);
	while (current != NULL)
	{
		index = 0;
		current2 = (*list);
		while (current2)
		{
			if (current2->data < current->data)
				index++;
			current2 = current2->next;
		}
		current->index = index;
		current = current->next;
	}
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                              GET THE INPUT                               */
/*                  take all input and put in the chained list              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static t_list	*get_input(t_list **list, char *tab[], int i)
{
	t_list	*current;
	int		data;
	int		j;

	j = 1;
	data = ft_atol(tab[j]);
	*list = ft_new_node(data);
	current = *list;
	while (j++ < i)
	{
		data = ft_atol(tab[j]);
		current = ft_new_node(data);
		ft_lstadd_back(list, current);
	}
	current->next = NULL;
	return (*list);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                  MAIN                                    */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc == 1)
		return (0);
	if (argc < 2 || !handle_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc == 2)
		list_a = split_it(&list_a, argv);
	else
		list_a = get_input(&list_a, argv, argc - 1);
	set_index(&list_a);
	list_b = NULL;
	sort(&list_a, &list_b);
	free_list(&list_a);
	return (0);
}

/*static void	display_list(t_list *list_a, t_list *list_b)
{
	while (list_a != NULL)
	{
		ft_printf("index :%d      %d", list_a->index, list_a->data);
		if (list_b != NULL)
		{
			ft_printf(" list_b :%d\n", list_b->data);
			list_b = list_b->next;
		}
		else
			ft_printf("\n");
		list_a = list_a->next;
	}
	while (list_b != NULL)
	{
		ft_printf(" list_b :%d\n", list_b->data);
		list_b = list_b->next;
	}
	ft_printf("_ _\na b\n");
}*/