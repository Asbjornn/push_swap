/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:52:02 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/22 11:30:26 by gcauchy          ###   ########.fr       */
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
/*

COURAGE GABIN BEBOU TU PEUX LE FAIRE -xXcriprou0CroupaXx

STOCKER DANS UN TEMP LE TABLO
SI ARGC == 2, TABLO = -> SPLIT
SINON PASSER A ARGV + 1 (apres a.out)
BOUCLER SUR L'ARRAY
{
	atoi de TABLO[i]
	si pas digit
	si pas double
	si pas limite
}
free TABLO si argc == 2
*/
