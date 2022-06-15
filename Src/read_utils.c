/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:59:31 by yson              #+#    #+#             */
/*   Updated: 2022/06/15 21:08:01 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	path_check(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i--] == 'b')
	{
		if (path[i--] == 'u')
		{
			if (path[i--] == 'c')
			{
				if (path[i] == '.')
					return (1);
			}
		}
	}
	return (0);
}

int	map_valid_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("01NSEW ", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arg_check(int argc, char **argv, t_map_info *info)
{
	if (argc != 2 || !path_check(argv[1]))
		return (0);
	info->map_fd = open(argv[1], O_RDONLY);
	if (info->map_fd < 0)
		return (0);
	return (1);
}

int	map_info_check(t_map_info *info)
{
	if (!info->img[0].img_ptr)
		return (0);
	if (!info->img[1].img_ptr)
		return (0);
	if (!info->img[2].img_ptr)
		return (0);
	if (!info->img[3].img_ptr)
		return (0);
	if (!info->floor_flag)
		return (0);
	if (!info->ceiling_flag)
		return (0);
	return (1);
}
