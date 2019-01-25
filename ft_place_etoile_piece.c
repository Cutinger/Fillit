/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_etoile_piece.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:44:46 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/23 19:45:52 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_cut_y(char **tab, int piece, int y, int x)
{
	int value;
	int tmp;
	int nb;

	nb = -1;
	while (++nb < piece)
	{
		y = 4 * nb;
		x = -1;
		while (++x < 4)
		{
			value = -1;
			tmp = 0;
			while (++value < 4 && tab[y][x] != '#' && ++y)
				tmp++;
			if (tmp == 4)
				while (value > 0)
				{
					tab[--y][x] = '*';
					value--;
				}
			y = value == 0 ? y : y - tmp;
		}
	}
	return (NULL);
}

char	**ft_place_etoile_piece(char **tab, int piece, int x, int y)
{
	int value;

	while (tab[++y])
	{
		x = -1;
		value = 0;
		while (tab[y][++x])
		{
			if (tab[y][x] && tab[y][x] == '.')
				value++;
			if (value == 4)
			{
				while (x >= 0 && tab[y][x] == '.')
				{
					tab[y][x] = '*';
					x--;
				}
				value = 0;
			}
		}
	}
	return (ft_cut_y(tab, piece, -1, -1));
}
