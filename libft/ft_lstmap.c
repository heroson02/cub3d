/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:03:46 by yson              #+#    #+#             */
/*   Updated: 2021/07/06 11:35:48 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;

	if (!lst || !*f)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (0);
	lst = lst->next;
	while (lst)
	{
		curr = ft_lstnew(f(lst->content));
		if (!curr)
		{
			ft_lstclear(&head, *del);
			return (0);
		}
		ft_lstadd_back(&head, curr);
		lst = lst->next;
	}
	return (head);
}
