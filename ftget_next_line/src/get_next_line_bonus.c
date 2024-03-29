/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:42:26 by tochen            #+#    #+#             */
/*   Updated: 2024/01/28 00:26:35 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

// returns 1 if to return, 0 if error, 2 if to continue
static int	process_buffer(char **line, char **buffer, int fd)
{
	char	*temp;
	char	*rest;
	char	*pos;

	pos = ft_strchr(buffer[fd], '\n');
	rest = NULL;
	if (pos)
	{
		rest = ft_strdup(pos + 1);
		if (!rest)
			return (0);
		pos[1] = '\0';
	}
	temp = ft_strjoin(*line, buffer[fd]);
	if (!temp)
		return (0);
	free(*line);
	*line = temp;
	if (pos)
		ft_strlcpy(buffer[fd], rest, BUFFER_SIZE + 1);
	else
		buffer[fd][0] = 0;
	free(rest);
	return (1 + !pos);
}

static int	read_into_line(int fd, char **buffer, char **line)
{
	ssize_t	bytes_read;
	int		state;

	bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	if (bytes_read < 0)
		return (0);
	while (bytes_read > 0)
	{
		buffer[fd][bytes_read] = '\0';
		state = process_buffer(line, buffer, fd);
		if (state != 2)
			return (state);
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (1);
}

static int	init_buffer(char **buffer, int fd)
{
	if (!buffer[fd])
	{
		buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer[fd])
			return (0);
		buffer[fd][0] = 0;
	}
	return (1);
}

static char	*clean(char **buffer, char *line, int fd, int state)
{
	if (state == 0 || ft_strlen(buffer[fd]) == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	if (!line)
		return (line);
	else if (state == 0 || ft_strlen(line) == 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;
	int			state;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (!buffer[fd] && !init_buffer(buffer, fd))
		return (NULL);
	state = process_buffer(&line, buffer, fd);
	if (state == 0)
		return (clean(buffer, line, fd, state));
	else if (state == 1)
		return (clean(buffer, line, fd, state));
	state = read_into_line(fd, buffer, &line);
	return (clean(buffer, line, fd, state));
}
