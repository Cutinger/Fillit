/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:57:21 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/23 15:18:02 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

char	*ft_rpetoile(char *s, size_t n)
{
	while (n--)
	{
		*s = '.';
		s++;
	}
	*s = '\0';
	return (s);
}

int		ft_check(char **map, t_etris *stock, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (stock->tetri[++i])
	{
		if (map[x + i] == 0)
			return (0);
		j = -1;
		while (stock->tetri[i][++j])
		{
			if (map[x + i][y + j] == 0)
				return (0);
			if (stock->tetri[i][j] != '.' && map[x + i][y + j] != '.')
				return (0);
		}
	}
	return (1);
}
