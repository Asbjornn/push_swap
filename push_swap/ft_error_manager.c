/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:52:02 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/20 17:13:29 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                          CHECK IF DOUBLE IN INPUT                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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
			if (ft_atol(tab[i]) == ft_atol(tab[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                           CHECK IF ONLY DIGIT                            */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-' || str[0] == '+')
			i++;
		else
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                            HANDLE ERRORS INPUT                           */
/*          check all input:                                                */
/*          if not a digit, out of int limit or if there is double          */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static int	loop_error_check(char **temp_argv)
{
	int			i;
	long int	temp;

	i = 0;
	temp = 0;
	while (temp_argv[i])
	{
		if (!check_digit(temp_argv[i]))
			return (0);
		temp = ft_atol(temp_argv[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	handle_error_split(char **argv)
{
	char		**temp_argv;
	int			result;

	result = 1;
	temp_argv = ft_split(argv[1], ' ');
	if (!temp_argv)
		return (0);
	if (!temp_argv[0])
	{
		free_all(temp_argv);
		return (0);
	}
	result = loop_error_check(temp_argv);
	if (check_double(temp_argv))
		result = 0;
	free_all(temp_argv);
	return (result);
}

int	handle_error(char **argv)
{
	int			i;
	long int	temp;
	char		**temp_argv;

	i = 0;
	temp_argv = argv + 1;
	if (!temp_argv[i])
		return (0);
	while (temp_argv[i])
	{
		if (!check_digit(temp_argv[i]))
			return (0);
		temp = ft_atol(temp_argv[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		i++;
	}
	if (check_double(temp_argv))
		return (0);
	return (1);
}
