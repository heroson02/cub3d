/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:29:42 by yson              #+#    #+#             */
/*   Updated: 2022/06/15 23:53:17 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_ad(char *s1, char *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, s1_len + 1);
	free(s1);
	ft_strlcat(newstr + (s1_len), s2, s2_len + 1);
	return (newstr);
}

int	is_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	split_line(char **backup, char **line, int cut_idx)
{
	char	*temp;
	int		len;

	(*backup)[cut_idx] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + cut_idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int	return_all(char **backup, char **line, int read_size)
{
	int	cut_idx;

	if (read_size < 0)
		return (-1);
	if (*backup)
	{
		cut_idx = is_newline(*backup);
		if (cut_idx >= 0)
			return (split_line(backup, line, cut_idx));
	}
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut_idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (!(read_size > 0))
			break ;
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin_ad(backup[fd], buf);
		cut_idx = is_newline(backup[fd]);
		if (cut_idx >= 0)
			return (split_line(&backup[fd], line, cut_idx));
	}
	return (return_all(&backup[fd], line, read_size));
}
