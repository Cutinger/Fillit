/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lettre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:30:41 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/23 18:11:06 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lettre(t_etris *stock)
{
	int i;
	int j;
	int nb;
	int lettre;

	lettre = 'A';
	nb = 0;
	while (stock[nb].tetri != NULL)
	{
		i = 0;
		while (stock[nb].tetri[i] != NULL)
		{
			j = 0;
			while (stock[nb].tetri[i][j])
			{
				if (stock[nb].tetri[i][j] == '#')
					stock[nb].tetri[i][j] = lettre;
				j++;
			}
			i++;
		}
		nb++;
		lettre++;
	}
}
