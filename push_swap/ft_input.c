/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:52:02 by gcauchy           #+#    #+#             */
/*   Updated: 2025/05/21 16:18:16 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	handle_error(char **tab)
{
	int	i;
	int	j;
	int	h;

	i = 1;
	while (tab[i])
	{
		h = 0;
		j = h + 1;
		if (tab[i][h] <= '0' || tab[i][h] >= '9')
			return (0);
		// if (tab[i] > 2147483647 || tab[i] < -2147483648)
		// 	return (0);
		while (tab[i][j])
		{
			if (tab[i][j] == tab[i][h])
				return (0);
			j++;
		}
		i++;
	}
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
