/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:36 by yson              #+#    #+#             */
/*   Updated: 2022/06/15 14:43:53 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	count_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	map_valid_check(char *str)
{
	int i;

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

t_type	source_type(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (E_NO);
	else if (str[0] == 'S' && str[1] == 'O')
		return (E_SO);
	else if (str[0] == 'W' && str[1] == 'E')
		return (E_WE);
	else if (str[0] == 'E' && str[1] == 'A')
		return (E_EA);
	else if (str[0] == 'F' && str[1] == ' ')
		return (E_FLOOR);
	else if (str[0] == 'C' && str[1] == ' ')
		return (E_CEILING);
	else if (map_valid_check(str))
		return (E_MAP);
	else
		return (E_ERROR);
}

void	remove_space(char **str, t_type type)
{
	char **split;
	int		count;

	if (type == E_MAP)
		return ;
	split = ft_split(*str, ' ');
	if (!split)
		err_exit("malloc error");
	count = count_arr(split);
	if (count > 2 || count < 2)
		err_exit("Wrong amount of key (texture)");
	free(*str);
	*str = ft_strdup(split[1]);
	free_split(split);
}

void	handle_texture(t_game *game, char *path, t_type type)
{
	if (type == E_NO)
		game->map.img[0] = load_img(game->mlx_ptr, WALL_WIDTH, WALL_HEIGHT, path, game->win_ptr);
	else if (type == E_EA)
		 game->map.img[1] = load_img(game->mlx_ptr, WALL_WIDTH, WALL_HEIGHT, path, game->win_ptr);
	else if (type == E_WE)
		game->map.img[2] = load_img(game->mlx_ptr, WALL_WIDTH, WALL_HEIGHT, path, game->win_ptr);
	else if (type == E_SO)
		game->map.img[3] = load_img(game->mlx_ptr, WALL_WIDTH, WALL_HEIGHT, path, game->win_ptr);
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
		err_exit("Wrong amount of key (rgb)");
	if (type == E_FLOOR)
	{
		info->floor = ft_atoi_ad(split[0]) << 16 | ft_atoi_ad(split[1]) << 8 | ft_atoi_ad(split[2]);
		info->floor_flag = 1;
	}
	else if (type == E_CEILING)
	{
		info->ceiling = ft_atoi_ad(split[0]) << 16 | ft_atoi_ad(split[1]) << 8 | ft_atoi_ad(split[2]);
		info->ceiling_flag = 1;
	}
	free_split(split);
}

int	handle_source(t_game *game, char *str, t_type type)
{
	remove_space(&str, type);
	if (type == E_NO || type == E_SO || type == E_WE || type == E_EA)
		handle_texture(game, str, type);
	else if (type == E_FLOOR || type == E_CEILING)
		handle_color(&game->map, str, type);
	else
		ft_lstadd_back(&game->map.map_lst, ft_lstnew(ft_strdup(str)));
	free(str);
	return (1);
}

void read_map(t_game *game)
{
	char	*temp;
	t_type	type;
	int		ret;

	while (1)
	{
		ret = get_next_line(game->map.map_fd, &temp);
		if (ret < 0)
			err_exit("read error");
		else if (ret == 0)
			break ;
		type = source_type(temp);
		if (type == E_ERROR)
			err_exit("Wrong source id");
		handle_source(game, temp, type);
	}
	if (!map_info_check(&game->map))
		err_exit("Wrong sources");
	game->map.map = lst_to_arr(game->map.map_lst);
}
