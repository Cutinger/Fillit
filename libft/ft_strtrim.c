/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:05:03 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:28:07 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <string.h>

static int	ft_len(char const *s)
{
	int		i;
	size_t	j;
	int		c;

	j = 0;
	c = -1;
	i = ft_strlen(s);
	while (s[++c])
		if (s[c] == ' ' || s[c] == '\t' || s[c] == '\n')
			j++;
	if (j == ft_strlen(s))
		return (1);
	return (0);
}

static int	ft_find(char const *s, int *i)
{
	size_t	len;

	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		len--;
		s++;
		(*i)++;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	int		j;
	int		len;
	int		i;

	tmp = 0;
	j = 0;
	i = 0;
	if (s)
	{
		if (ft_len(s) == 1)
			return (ft_strdup(""));
		len = ft_find(s, &i);
		if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (len--)
			tmp[j++] = s[i++];
		tmp[j] = '\0';
		return (tmp);
	}
	return (NULL);
}
