/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:15:07 by yson              #+#    #+#             */
/*   Updated: 2021/05/12 15:23:02 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*cur;
	unsigned char	target;

	target = (unsigned char)c;
	cur = (unsigned char *)str;
	while (1)
	{
		if (*cur == target)
			return ((char *)cur);
		if (!*cur)
			return (0);
		cur++;
	}
}
