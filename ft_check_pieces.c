/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:57:17 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/25 14:36:19 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkpiece(char *tmp, int *d)
{
	int nb;
	int htag;
	int rep;

	rep = *d;
	htag = 0;
	nb = 0;
	while (htag != 4)
	{
		if (tmp[*d] == '#')
		{
			htag++;
			if (*d >= 5)
				tmp[*d - 5] == '#' && *d - 5 >= rep ? nb++ : 0;
			tmp[*d + 5] == '#' && *d + 5 <= rep + 18 ? nb++ : 0;
			tmp[*d + 1] == '#' ? nb++ : 0;
			if (*d >= 1)
				tmp[*d - 1] == '#' ? nb++ : 0;
		}
		(*d)++;
	}
	(*d) = rep + 21;
	return (nb == 6 || nb == 8 ? 1 : 0);
}

int		ft_double_check(char *tmp, int i)
{
	if (tmp[i + 1] == '\0' && tmp[i] == '\n' && tmp[i - 1] == '\n')
		return (0);
	if (tmp[i] == '\n' && tmp[i + 1] == '\n' && tmp[i + 2] == '\n')
		return (0);
	return (1);
}

int		check(char *tmp, int i, int *piece, int d)
{
	int j[3];

	j[0] = 0;
	j[1] = 0;
	j[2] = 0;
	(*piece)++;
	while (tmp[i] || tmp[i] == '.' || tmp[i] == '#' || tmp[i] == '\n')
	{
		tmp[i] == '#' ? j[0]++ : 0;
		tmp[i] == '.' ? j[1]++ : 0;
		tmp[i] == '\n' ? j[2]++ : 0;
		if (!(ft_double_check(tmp, i)))
			return (0);
		if ((j[0] == 4 && j[2] == 5 && j[1] == 12)
			|| (j[0] == 4 && j[2] == 4 && j[1] == 12
				&& tmp[i + 1] == '\0'))
			return (checkpiece(tmp, &d) == 1 ? check(tmp, i + 1, piece, d) : 0);
		i++;
	}
	if (j[0] == 0 && j[1] == 0)
		return (*piece > 0 ? 1 : 0);
	return (0);
}
