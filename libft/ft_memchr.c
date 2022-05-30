/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:20:26 by yson              #+#    #+#             */
/*   Updated: 2021/05/10 22:52:26 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	new_c;

	i = 0;
	new_c = (unsigned int)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == new_c)
			return (str);
		str++;
		i++;
	}
	return (0);
}
