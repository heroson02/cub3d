/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:12:01 by yson              #+#    #+#             */
/*   Updated: 2022/05/23 18:46:20 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	err_exit(void)
{
	ft_putstr_fd("Error\n", 1);
}

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

int	arg_check(int argc, char **argv, t_info *info)
{
	if (argc != 2 || !path_check(argv[1]))
		return (0);
	info->map_fd = open(argv[1], O_RDONLY);
	if (info->map_fd < 0)
		return (0);
	return (1);
}

int	map_info_check(t_info *info)
{
	if (!info->no)
		return (0);
	if (!info->so)
		return (0);
	if (!info->we)
		return (0);
	if (!info->ea)
		return (0);
	if (!&(info->floor))
		return (0);
	if (!&(info->ceilling))
		return (0);
	return (1);
}

int	map_check(t_info *info)
{
	char	*temp;
	char	**split;

	while (1)
	{
		if (get_next_line(info->map_fd, &temp) < 0)
			err_exit();
		split = ft_split(temp, ' ');
		if (count_arr(split) != 2)
		free(temp);
		if (!map_info_check(info))
			break ;
	}
	while (1)
	{
		if (get_next_line(info->map_fd, &temp) < 0)
			err_exit();
		free(temp);
	}
	
}

int main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	if (!arg_check(argc, argv, &info))
		err_exit();
	// if (!map_check(&info))
	// 	err_exit();
	return (0);
}
