/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:21:13 by yson              #+#    #+#             */
/*   Updated: 2022/06/15 17:35:51 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

void	err_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	free_node(void *content)
{
	free(content);
	content = 0;
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

void	get_width_height(int *wid, int *hei, t_list *head)
{
	int				size;
	unsigned int	longest_width;
	t_list	*curr;

	size = 0;
	curr = head;
	longest_width = ft_strlen(head->content);
	while (curr)
	{
		if (longest_width < ft_strlen(curr->content))
			longest_width = ft_strlen(curr->content);
		size++;
		curr = curr->next;
	}
	*wid = longest_width;
	*hei = size;
}

void	fill_with_space(char **map, int wid, int hei)
{
	int i;

	i = 0;
	// printf("width : %d, height : %d\n", wid, hei);
	while (i < hei)
	{
		map[i] = malloc(wid + 1);
		if (!map[i])
			err_exit("malloc error");
		ft_memset(map[i], ' ', wid);
		map[i][wid] = '\0';
		i++;
	}
}

char	**lst_to_arr(t_game *game, t_list *head)
{
	int		i;
	char	**result;
	t_list	*curr;

	i = 0;
	curr = head;
	get_width_height(&game->map.map_width, &game->map.map_height, head);
	// printf("width : %d, height : %d\n", game->map.map_width, game->map.map_height);
	result = malloc(sizeof(char *) * (game->map.map_height + 1));
	if (!result)
		err_exit("malloc error");
	fill_with_space(result, game->map.map_width, game->map.map_height);
	while (i < game->map.map_height)
	{
		ft_strncpy(result[i], curr->content, ft_strlen(curr->content));
		curr = curr->next;
		i++;
	}
	ft_lstclear(&head, free_node);
	return (result);
}
