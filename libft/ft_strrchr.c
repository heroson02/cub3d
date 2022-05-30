/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:22:27 by yson              #+#    #+#             */
/*   Updated: 2021/05/12 15:25:31 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char			*cur;
	int						i;
	unsigned char			target;

	i = 0;
	target = (unsigned char)c;
	cur = (unsigned char *)str;
	while (cur[i])
		i++;
	if (target == 0)
		return ((char *)(cur + i));
	while (i >= 0)
	{
		if (cur[i] == target)
			return ((char *)(cur + i));
		i--;
	}
	return (0);
}
