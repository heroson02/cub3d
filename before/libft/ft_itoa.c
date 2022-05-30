/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:12:51 by yson              #+#    #+#             */
/*   Updated: 2021/07/06 11:42:10 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		n_len;
	int		i;
	char	*result;

	n_len = ft_numlen(n);
	i = n_len - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(n_len + 1);
	if (!result)
		return (0);
	if (n_len == 1)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n != 0)
	{
		if (n > 0)
			result[i--] = 48 + n % 10;
		else
			result[i--] = 48 + -n % 10;
		n /= 10;
	}
	result[n_len] = '\0';
	return (result);
}
