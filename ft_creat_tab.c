/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:09:46 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/23 19:27:52 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char**ft_create_pieces(char **tmp, char **tab, int *i, int a)
{
	int j[3];

	j[2] = 0;
	while (!j[2])
	{
		j[1] = 0;
		j[0] = 0;
		while (tab[*i][j[0]] == '*')
			j[0]++;
		while (tab[*i][j[0]] == '#' || tab[*i][j[0]] == '.')
		{
			tmp[a][j[1]] = tab[*i][j[0]];
			j[0]++;
			j[1]++;
			j[2]++;
		}
		if (!j[2])
		{
			(*i)++;
			j[0] = 0;
		}
	}
	tmp[a][j[1]] = '\0';
	(*i)++;
	return (tmp);
}

void*ft_free(char **tab, int nt)
{
	while (nt)
		ft_strdel(&tab[nt--]);
	free(tab);
	return (NULL);
}

char**ft_creattab(char **tab, int i)
{
	char	**tmp;
	int		j;
	int		nt;
	int		d;

	j = i;
	d = ft_nb_of(tab, i, 0, 0);
	nt = -1;
	if (!(tmp = malloc(sizeof(char *) * ((ft_nb_of(tab, i, 0, 0) + 1)))))
		return (NULL);
	while (++nt < d)
	{
		if (!(tmp[nt] = malloc(sizeof(char) * ((ft_nb_of_y(tab, j) + 1)))))
		{
			ft_free(tab, nt);
			return (NULL);
		}
		int f ;
		f = ft_nb_of_y(tab, j);
		ft_create_pieces(tmp, tab, &i, nt);
	}
	tmp[nt] = NULL;
	return (tmp);
}
