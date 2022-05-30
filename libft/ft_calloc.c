/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:11:47 by yson              #+#    #+#             */
/*   Updated: 2021/07/06 11:40:39 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*result;

	result = malloc(count * size);
	if (!result)
		return (0);
	return (ft_memset(result, 0, count * size));
}
