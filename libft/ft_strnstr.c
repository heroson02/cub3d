/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:07:14 by yson              #+#    #+#             */
/*   Updated: 2021/05/10 22:51:49 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	n;

	n = ft_strlen((char *)to_find);
	if (!*to_find)
		return ((char *)str);
	while (*str && len >= n)
	{
		if (ft_strncmp(str, to_find, n) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (0);
}
