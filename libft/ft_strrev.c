/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:58:14 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:27:43 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (str[i])
	{
		i++;
	}
	while (p < i / 2)
	{
		tmp = str[p];
		str[p] = str[i - p - 1];
		str[i - p - 1] = tmp;
		p++;
	}
	return (str);
}
