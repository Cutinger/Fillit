/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:19:10 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:27:32 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		t;

	t = ft_strlen(s2);
	if (t == 0)
		return ((char *)s1);
	while (*s1 && t <= len--)
	{
		if (ft_strncmp(s1, s2, t) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
