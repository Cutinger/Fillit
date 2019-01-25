/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:54:30 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:23:08 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*x;
	unsigned char	y;
	size_t			i;

	x = (unsigned char *)s;
	y = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (x[i] == y)
			return (&x[i]);
	return (NULL);
}
