/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:11:02 by yson              #+#    #+#             */
/*   Updated: 2021/05/07 17:05:00 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*result;
	unsigned char	*from;
	unsigned char	new_c;

	i = 0;
	new_c = (unsigned char)c;
	result = (unsigned char *)dst;
	from = (unsigned char *)src;
	while (i < n)
	{
		*result = *from;
		if (*from == new_c)
		{
			result++;
			return (result);
		}
		from++;
		result++;
		i++;
	}
	return (0);
}
