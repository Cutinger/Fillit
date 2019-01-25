/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:34:08 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:39:36 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static char		ft_nb_of(char *str)
{
	int		i;
	int		count;
	int		nbw;
	int		flag;

	flag = 0;
	nbw = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
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

static char		ft_nb_car(char *str, int *i)
{
	int nb;

	nb = 0;
	if (str[*i])
	{
		while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t')
			(*i)++;
		while (str[*i] != ' ' && str[*i] != '\n' && str[*i] != '\t' && str[*i])
		{
			(*i)++;
			nb++;
		}
		nb--;
		return (nb);
	}
	return (nb);
}

static char		*ft_work(char *str, char *tab, int *d)
{
	int		j;

	j = 0;
	while (str[*d] == ' ' || str[*d] == '\n' || str[*d] == '\t')
		(*d)++;
	while (str[*d] != ' ' && str[*d] != '\n' && str[*d] != '\t' && str[*d])
	{
		tab[j] = str[*d];
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

char			**ft_split_whitespaces(char *str)
{
	int		i;
	char	**tab;
	int		nt;
	int		d;

	d = 0;
	nt = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (ft_nb_of(str) + 1))))
		return (NULL);
	while (nt < ft_nb_of(str))
	{
		if (!(tab[nt] = malloc(sizeof(char) * ft_nb_car(str, &i))))
			ft_free(tab, nt);
		tab[nt] = ft_work(str, tab[nt], &d);
		nt++;
	}
	tab[nt] = 0;
	return (tab);
}
