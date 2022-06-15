/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:54:17 by yson              #+#    #+#             */
/*   Updated: 2022/06/15 20:56:28 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

void	free_node(void *content)
{
	free(content);
	content = 0;
}

void	get_width_height(int *wid, int *hei, t_list *head)
{
	int				size;
	unsigned int	longest_width;
	t_list			*curr;

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
	int	i;

	i = 0;
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
	result = malloc(sizeof(char *)
			* (game->map.map_height + 1));
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
