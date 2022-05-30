/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:29:42 by yson              #+#    #+#             */
/*   Updated: 2021/05/20 22:45:58 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*cur;
	unsigned char	target;

	target = (unsigned char)c;
	cur = (unsigned char *)str;
	while (1)
	{
		if (*cur == target)
			return ((char *)cur);
		if (!*cur)
			return (0);
		cur++;
	}
}

int		put_line(char **line, char *nl_next, char **backup)
{
	char	*temp;

	if (nl_next)
	{
		nl_next[0] = '\0';
		temp = ft_strdup(nl_next + 1);
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = temp;
		return (1);
	}
	else if (*backup)
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = 0;
	}
	else
		*backup = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char *backup[MAX_FD];
	char		*nl_next;
	char		*temp;
	int			file_len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	while ((nl_next = ft_strchr(backup[fd], '\n')) == 0
	&& (file_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[file_len] = '\0';
		temp = ft_strjoin(backup[fd], buffer);
		free(backup[fd]);
		backup[fd] = temp;
	}
	free(buffer);
	if (file_len == -1)
		return (-1);
	return (put_line(line, nl_next, &backup[fd]));
}
