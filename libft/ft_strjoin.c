/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 22:02:13 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:26:32 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size;

	size = 0;
	join = NULL;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if (!(join = (char *)malloc(sizeof(*join) * (size + 1))))
			return (NULL);
		while (*s1)
			*join++ = *s1++;
		while (*s2)
			*join++ = *s2++;
		*join = '\0';
	}
	return (join - size);
}
