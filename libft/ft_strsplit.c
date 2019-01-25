/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 05:11:36 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/23 15:36:45 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static char		ft_nb_of(char *s, char c)
{
	int		i;
	int		count;
	int		flag;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
			count++;
		flag = 0;
	}
	return (count);
}

static int		ft_nb_car(char *s, int *i, char c)
{
	int nb;

	nb = 0;
	if (s[*i])
	{
		while (s[*i] == c)
			(*i)++;
		while (s[*i] != c && s[*i])
		{
			(*i)++;
			nb++;
		}
		return (nb);
	}
	return (nb);
}

static char		*ft_work(char *s, char *tab, int *d, char c)
{
	int j;

	j = 0;
	while (s[*d] == c)
		(*d)++;
	while (s[*d] != c && s[*d])
	{
		tab[j] = s[*d];
		(*d)++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static void		*ft_free(char **tab, int nt)
{
	while (nt)
		ft_strdel(&tab[nt--]);
	free(tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;
	int		nt;
	int		d;

	d = 0;
	nt = 0;
	i = 0;
	if (!(s))
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (ft_nb_of((char *)s, c) + 1))))
		return (NULL);
	while (nt < ft_nb_of((char *)s, c))
	{
		if (!(tab[nt] = malloc(sizeof(char) * ft_nb_car((char *)s, &i, c) + 1)))
			ft_free(tab, nt);
		tab[nt] = ft_work((char *)s, tab[nt], &d, c);
		nt++;
	}
	tab[nt] = 0;
	return (tab);
}
