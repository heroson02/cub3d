/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:36 by yson              #+#    #+#             */
/*   Updated: 2022/06/15 22:40:05 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

void	remove_space(char **str, t_type type)
{
	char	**split;
	int		count;

	if (type == E_MAP)
		return ;
	split = ft_split(*str, ' ');
	if (!split)
		err_exit("malloc error");
	count = count_arr(split);
	if (count > 2 || count < 2)
		err_exit("wrong amount of value");
	free(*str);
	*str = ft_strdup(split[1]);
	free_split(split);
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

void	read_map(t_game *game)
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
			err_exit("Wrong map source");
		handle_source(game, temp, type);
	}
	if (!map_info_check(&game->map))
		err_exit("Wrong sources");
	game->map.map = lst_to_arr(game, game->map.map_lst);
}
