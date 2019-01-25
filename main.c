/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:09:22 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/25 14:53:11 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_arg(int argc)
{
	if (argc == 1)
	{
		write(2, "fillit: missing file operand.", 29);
		return (0);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.", 19);
		return (0);
	}
	return (1);
}

void	ft_print_words_tables(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}
}

void	*ft_free_map(char **tab)
{
	int nt;

	nt = -1;
	while (tab[++nt])
	{
		ft_strdel(&tab[nt]);
	}
	free(tab);
	return (NULL);
}

int		ft_lets_do_it(char **tab, int piece)
{
	t_etris *stock;
	char	**map;
	char	**tmp;
	int		i;

	i = -1;
	map = NULL;
	tmp = NULL;
	stock = NULL;
	ft_place_etoile_piece(tab, piece, -1, -1);
	stock = ft_make_struct(tab, piece, stock);
	map = ft_createmap(piece, map);
	tmp = map;
	while (ft_backcrack(map, 0, stock))
	{
		ft_free_map(tmp);
		map = ft_createmap(piece++, map);
		tmp = map;
	}
	ft_print_words_tables(map);
	ft_free_map(map);
	while (stock[++i].tetri)
		ft_free_map(stock[i].tetri);
	free(stock);
	return (0);
}

int		main(int argc, char **argv)
{
	char	tmp[BUFF_SIZE + 1];
	int		fd;
	int		piece;
	char	**tab;
	int		value;

	tab = NULL;
	piece = -1;
	fd = open(argv[1], O_RDONLY);
	if (test_arg(argc) == 0)
		return (0);
	if ((value = read(fd, tmp, BUFF_SIZE)) <= 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (check(tmp, 0, &piece, 0) < 1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	tab = ft_strsplit(tmp, '\n');
	ft_lets_do_it(tab, piece);
	ft_free_map(tab);
	return (0);
}
