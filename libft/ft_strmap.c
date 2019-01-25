/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 05:53:33 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:26:45 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	if (s)
	{
		if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[++i])
			str[i] = (*f)(s[i]);
		str[i] = '\0';
	}
	return (str);
}
