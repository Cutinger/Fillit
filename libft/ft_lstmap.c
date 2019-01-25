/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:07:40 by gogrkovi          #+#    #+#             */
/*   Updated: 2018/12/18 17:22:30 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *str;
	t_list *tmp;
	t_list *deb;

	if (!(lst || f))
		return (NULL);
	tmp = f(lst);
	if (!(str = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	deb = str;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(str->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			free(str);
			return (NULL);
		}
		str = str->next;
		lst = lst->next;
	}
	return (deb);
}
