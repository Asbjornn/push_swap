/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:37:32 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/19 15:54:50 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
t_list	*ft_new_node(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *list);

void	ft_sa(t_list **list_a);
void	ft_sb(t_list **list_b);
void	ft_ss(t_list **list_a, t_list **list_b);

void	ft_ra(t_list **list_a);
void	ft_rb(t_list **list_b);
void	ft_rr(t_list **list_a, t_list **list_b);

void	ft_rra(t_list **list_a);
void	ft_rrb(t_list **list_a);
void	ft_rrr(t_list **list_a, t_list **list_b);

void	ft_pa(t_list **src, t_list **dest);
void	ft_pb(t_list **src, t_list **dest);

void	sort(t_list **list_a, t_list **list_b);
void	sort3(t_list **list);
void    radix_bitwise(t_list **list_a, t_list **list_b);
void	chunk_sort(t_list **list_a, t_list **list_b);

#endif