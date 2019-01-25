/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:00:55 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:26:49 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = -1;
	str = NULL;
	if (s && f)
	{
		if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[++i])
			str[i] = (*f)(i, s[i]);
		str[i] = '\0';
	}
	return (str);
}
