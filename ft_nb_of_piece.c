/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_of_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:33:54 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/17 23:36:05 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nb_of(char **str, int i, int count, int flag)
{
	int		nt;
	int		j;

	nt = i + 4;
	j = 0;
	while (i < nt)
	{
		while (str[i][j])
		{
			if (str[i][j] != '*')
				flag = 1;
			j++;
		}
		if (flag == 1)
		{
			count++;
			flag = 0;
		}
		i++;
		j = 0;
	}
	return (count);
}
