/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:01:02 by yson              #+#    #+#             */
/*   Updated: 2022/06/16 18:55:18 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

void	handle_texture(t_game *game, char *path, t_type type)
{
	if (type == E_NO)
		game->map.img[0] = load_img(game->mlx_ptr, path, game->win_ptr);
	else if (type == E_EA)
		game->map.img[1] = load_img(game->mlx_ptr, path, game->win_ptr);
	else if (type == E_WE)
		game->map.img[2] = load_img(game->mlx_ptr, path, game->win_ptr);
	else if (type == E_SO)
		game->map.img[3] = load_img(game->mlx_ptr, path, game->win_ptr);
}

void	handle_color(t_map_info *info, char *str, t_type type)
{
	char	**split;
	int		count;

	split = ft_split(str, ',');
	if (!split)
		err_exit("malloc error");
	count = count_arr(split);
	if (count > 3 || count < 3)
		err_exit("wrong amount of value");
	if (type == E_FLOOR)
	{
		info->floor = ft_atoi_ad(split[0]) << 16
			| ft_atoi_ad(split[1]) << 8 | ft_atoi_ad(split[2]);
		info->floor_flag = 1;
	}
	else if (type == E_CEILING)
	{
		info->ceiling = ft_atoi_ad(split[0]) << 16
			| ft_atoi_ad(split[1]) << 8 | ft_atoi_ad(split[2]);
		info->ceiling_flag = 1;
	}
	free_split(split);
}

int	is_repeated(t_game *game, t_type type)
{
	if (type == E_NO && game->map.img[0].img_ptr)
		return (1);
	else if (type == E_EA && game->map.img[1].img_ptr)
		return (1);
	else if (type == E_WE && game->map.img[2].img_ptr)
		return (1);
	else if (type == E_SO && game->map.img[3].img_ptr)
		return (1);
	else if (type == E_FLOOR && game->map.floor_flag)
		return (1);
	else if (type == E_CEILING && game->map.ceiling_flag)
		return (1);
	return (0);
}

void	handle_source(t_game *game, char *str, t_type type)
{
	if (is_repeated(game, type))
		err_exit("source repeated");
	remove_space(&str, type);
	if (type == E_NO || type == E_SO || type == E_WE || type == E_EA)
		handle_texture(game, str, type);
	else if (type == E_FLOOR || type == E_CEILING)
		handle_color(&game->map, str, type);
	else
		ft_lstadd_back(&game->map.map_lst, ft_lstnew(ft_strdup(str)));
	free(str);
}
