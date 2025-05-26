/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:52:02 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/26 14:55:32 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	check_double(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		else if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	handle_error(int argc, char **argv)
{
	int			i;
	long int	temp;
	char		**temp_argv;

	i = 0;
	if (argc == 2)
		temp_argv = ft_split(argv[1], ' ');
	else
		temp_argv = argv + 1;
	if (!temp_argv[i])
		return (0);
	while (temp_argv[i])
	{
		if (!check_digit(temp_argv[i]))
			return (0);
		temp = ft_atoi(temp_argv[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		i++;
	}
	if (check_double(temp_argv))
		return (0);
	if (argc == 2)
		free_all(temp_argv);
	return (1);
}
