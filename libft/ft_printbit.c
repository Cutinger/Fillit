/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:51:50 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:23:59 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_printbit(unsigned char octet)
{
	unsigned char	i;

	i = 1 << 7;
	if (octet)
	{
		while (i > 0)
		{
			if (octet & i)
				ft_putchar('1');
			else
				ft_putchar('0');
			i >>= 1;
		}
	}
}
