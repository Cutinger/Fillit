/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:47:38 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:31:00 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*desst;

	i = 0;
	desst = (char *)dst;
	while (i < n)
	{
		desst[i] = ((char *)src)[i];
		if (desst[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
