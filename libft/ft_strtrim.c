/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:02:08 by yson              #+#    #+#             */
/*   Updated: 2021/07/06 11:39:59 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_back(const char *s1, const char *set)
{
	int		back_i;
	int		len;

	len = ft_strlen(s1);
	back_i = 0;
	while (back_i < len)
	{
		if (ft_strchr(set, s1[len - back_i - 1]) == 0)
			break ;
		back_i++;
	}
	return (len - back_i);
}

static int	check_forward(const char *s1, const char *set)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		back_i;
	char	*result;

	if (!set)
		return (ft_strdup(s1));
	i = check_forward(s1, set);
	back_i = check_back(s1, set);
	if (i >= back_i)
		return (ft_strdup(""));
	result = malloc(back_i - i + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1 + i, back_i - i + 1);
	return (result);
}
