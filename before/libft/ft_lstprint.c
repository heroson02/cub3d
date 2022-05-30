/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:36:05 by yson              #+#    #+#             */
/*   Updated: 2022/05/30 16:38:07 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	t_list *curr;

	if (!lst)
		return ;
	curr = lst;
	while (curr)
	{
		ft_putendl_fd(curr->content, 1);
		curr = curr->next;
	}
}
