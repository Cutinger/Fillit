/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:18:52 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:39:27 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	maj;

	i = 0;
	maj = 1;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (maj == 1 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			if (maj == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			maj = 0;
		}
		if (!((str[i] >= '0' && str[i] <= '9') ||
					(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' &&
						str[i] <= 'Z')))
			maj = 1;
		i++;
	}
	return (str);
}
