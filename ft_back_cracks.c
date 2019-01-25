/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_cracks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 00:11:56 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/23 19:46:23 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_remplissage(char **map, t_etris *stock, int x, int y)
{
	int		i;
	int		j;
	int		save;

	save = y;
	i = -1;
	while (stock->tetri[++i])
	{
		j = -1;
		y = save;
		while (stock->tetri[i][++j])
		{
			if (stock->tetri[i][j] != '.')
				map[x][y] = stock->tetri[i][j];
			y++;
		}
		x++;
	}
	return (map);
}

char		**ft_deletepiece(char **map, t_etris *stock, int x, int y)
{
	int		i;
	int		j;
	int		save;

	save = y;
	i = -1;
	while (stock->tetri[++i])
	{
		j = -1;
		y = save;
		while (stock->tetri[i][++j])
		{
			if (stock->tetri[i][j] != '.')
				map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}

int			ft_backcrack(char **map, int nt, t_etris *stock)
{
	int		x;
	int		y;

	x = -1;
	if (stock[nt].tetri == NULL)
		return (0);
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
			if (ft_check(map, &stock[nt], x, y))
			{
				ft_remplissage(map, &stock[nt], x, y);
				if (!ft_backcrack(map, nt + 1, stock))
					return (0);
				ft_deletepiece(map, &stock[nt], x, y);
			}
	}
	return (1);
}

char		**ft_createmap(int piece, char **map)
{
	int nt;

	nt = 0;
	if (!(map = malloc(sizeof(char *) * (ft_sqrt(piece * 4) + 1))))
		return (NULL);
	while (nt <	ft_sqrt(piece * 4))
	{
		if (!(map[nt] = malloc(sizeof(char) * ft_sqrt(piece * 4) + 1)))
		{
			ft_free(map, nt);
			return (NULL);
		}
		ft_rpetoile(map[nt], ft_sqrt(piece * 4));
		nt++;
	}
	map[nt] = NULL;
	return (map);
}

t_etris		*ft_make_struct(char **tab, int piece, t_etris *stock)
{
	int		i;
	int		u;

	i = -4;
	u = -1;

	if (!(stock = (t_etris *)malloc(sizeof(*stock) * (piece + 1))))
		return (NULL);
	while (++u < piece)
	{
		i += 4;
		stock[u].tetri = ft_creattab(tab, i);
		stock[u].nb = u;
	}
	stock[u].tetri = NULL;
	return (stock);
}
