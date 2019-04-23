/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:44:22 by rtroll            #+#    #+#             */
/*   Updated: 2018/11/24 21:29:15 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (lst == NULL)
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list));
	begin = new;
	while (lst->next != NULL)
	{
		*(new) = *(f(lst));
		new->next = (t_list*)malloc(sizeof(t_list));
		new = new->next;
		lst = lst->next;
	}
	*(new) = *(f(lst));
	new->next = NULL;
	return (begin);
}
