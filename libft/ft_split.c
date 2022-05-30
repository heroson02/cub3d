/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:34:48 by yson              #+#    #+#             */
/*   Updated: 2021/07/06 11:37:58 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	count_str(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && !(str[i] == c))
				i++;
		}
	}
	return (count);
}

static void	put_str(char *result, char *str, int index, int word_len)
{
	int	j;

	j = 0;
	while (j < word_len)
	{
		result[j] = str[index - word_len + j];
		j++;
	}
	result[j] = '\0';
}

static int	ft_split2(char ***result, char *str, char c, int word_count)
{
	int		i;
	int		word_len;
	int		count;

	count = 0;
	i = 0;
	word_len = 0;
	while (str[i] && count < word_count)
	{
		while (str[i] == c && str[i])
			i++;
		while (!(str[i] == c) && str[i])
		{
			word_len++;
			i++;
		}
		(*result)[count] = malloc(word_len + 1);
		if (!(*result)[count])
			return (0);
		put_str((*result)[count], str, i, word_len);
		word_len = 0;
		count++;
	}
	(*result)[count] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		flag;

	word_count = count_str((char *)s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (0);
	flag = ft_split2(&result, (char *)s, c, word_count);
	if (!flag)
	{
		free_all(result);
		return (0);
	}
	return (result);
}
