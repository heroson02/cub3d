/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:01:38 by yson              #+#    #+#             */
/*   Updated: 2022/05/30 17:14:19 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	free_split(char **split)
{
	int	idx;

	idx = -1;
	while (split[++idx])
	{
		free(split[idx]);
		split[idx] = 0;
	}
	free(split);
	split = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	if (len < ft_strlen(s2))
		len = ft_strlen(s2);
	return (ft_memcmp(s1, s2, len));
}

int	ft_atoi_ad(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			err_exit("put only number");
		i++;
	}
	return (ft_atoi(str));
}
