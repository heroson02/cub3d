/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:54:51 by yson              #+#    #+#             */
/*   Updated: 2021/05/10 22:51:06 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned int	count;
	unsigned char	*result;
	unsigned char	*from;

	result = (unsigned char *)dst;
	from = (unsigned char *)src;
	count = 0;
	if (result == from)
		return (0);
	if (dst <= src)
	{
		while (count < len)
		{
			result[count] = from[count];
			count++;
		}
	}
	else if (dst > src)
	{
		while (len-- > 0)
			result[len] = from[len];
	}
	return (result);
}
