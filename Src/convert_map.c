/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:33:00 by yson              #+#    #+#             */
/*   Updated: 2022/06/16 18:15:36 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	convert_source(char c)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	else if (ft_strchr("NSEW", c))
		return (0);
	else if (c == ' ')
		return (' ');
	return (0);
}

void	convert_map(t_game *game, int i, int j)
{
	int		**map;
	char	**pre_map;

	pre_map = game->map.map;
	map = malloc(sizeof(int *) * game->map.map_height);
	if (!map)
		err_exit("malloc error");
	while (pre_map[i] && i < game->map.map_height)
	{
		map[i] = malloc(sizeof(int) * game->map.map_width);
		if (!map[i])
			err_exit("malloc error");
		j = 0;
		while (pre_map[i][j] && j < game->map.map_width)
		{
			map[i][j] = convert_source(pre_map[i][j]);
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	game->map.world_map = map;
}
