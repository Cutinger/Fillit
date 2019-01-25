/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_caractere_piece.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:32:06 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/17 23:33:13 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nb_of_y(char **str, int i)
{
	int		nb;
	int		j;

	j = 0;
	nb = 0;
	while (!nb)
	{
		while (str[i][j] == '*')
			j++;
		while (str[i][j] == '.' || str[i][j] == '#')
		{
			j++;
			nb++;
		}
		(i)++;
		j = 0;
	}
	return (nb);
}
