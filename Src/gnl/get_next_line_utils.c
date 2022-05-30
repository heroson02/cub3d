/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:22:31 by yson              #+#    #+#             */
/*   Updated: 2021/05/20 17:18:43 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char			*ft_strdup(const char *src)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_strlen(src);
	if (!(str = malloc(size + 1)))
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	while ((dest_len + i + 1) < size && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (size > dest_len)
		return (src_len + dest_len);
	return (src_len + size);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	if (size == 0)
		return (count);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;

	size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(result = malloc(size + 1)))
		return (0);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, size + 1);
	return (result);
}
