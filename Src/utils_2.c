/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:21:13 by yson              #+#    #+#             */
/*   Updated: 2022/06/15 21:08:21 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

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
	int	i;
	int	result;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			err_exit("put only number");
		i++;
	}
	result = ft_atoi(str);
	if (result > 256 || result < 0)
		err_exit("out of rgb range");
	return (result);
}

int	count_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
