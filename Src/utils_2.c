/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:21:13 by yson              #+#    #+#             */
/*   Updated: 2022/05/31 23:33:52 by yson             ###   ########.fr       */
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
	while (i < hei)
	{
		map[i] = malloc(wid + 1);
		if (!map[i])
			err_exit("malloc error");
		ft_memset(map[i], '0', wid);
		map[i][wid] = '\0';
		i++;
	}
}

char	**lst_to_arr(t_list *head)
{
	int		wid;
	int		hei;
	int		i;
	char	**result;
	t_list	*curr;

	i = 0;
	curr = head;
	get_width_height(&wid, &hei, head);
	result = malloc(sizeof(char *) * (hei + 1));
	if (!result)
		err_exit("malloc error");
	fill_with_space(result, wid, hei);
	while (i < hei)
	{
		ft_strncpy(result[i], curr->content, sizeof(curr->content));
		curr = curr->next;
		i++;
	}
	//리스트 초기화하기
	return (result);
}
