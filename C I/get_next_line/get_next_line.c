/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:47:35 by achoukri          #+#    #+#             */
/*   Updated: 2024/11/27 21:41:13 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_static_buffer(int fd, char *static_buffer, char *buff)
{
	ssize_t		bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (!ft_strchr(static_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buff), free(static_buffer), NULL);
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0'; 
		if (!static_buffer)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(static_buffer, buff);
		if (!tmp)
			return (free(static_buffer), free(buff), NULL);
		free(static_buffer);
		static_buffer = tmp;
	}
	return (free(buff), static_buffer);
}

char	*extract_line(char *static_buffer)
{
	char	*newline_pos;
	char	*line;
	size_t	line_lenth;

	newline_pos = ft_strchr(static_buffer, '\n');
	if (newline_pos)
		line_lenth = newline_pos - static_buffer + 1;
	else
		line_lenth = ft_strlen(static_buffer);
	line = malloc(sizeof(char) * (line_lenth + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, static_buffer, line_lenth);
	line[line_lenth] = '\0';
	return (line);
}

char	*clean_static_buffer(char *static_buffer)
{
	char	*newline_pos;
	char	*cleaned_buffer;
	size_t	lenth_of_left_over_data;

	newline_pos = ft_strchr(static_buffer, '\n');
	if (!newline_pos)
		return (free(static_buffer), NULL);
	lenth_of_left_over_data = ft_strlen(newline_pos + 1);
	if (lenth_of_left_over_data == 0)
		return (free(static_buffer), NULL);
	cleaned_buffer = malloc(sizeof(char) * (lenth_of_left_over_data + 1));
	if (!cleaned_buffer)
		return (NULL);
	ft_memcpy(cleaned_buffer, newline_pos + 1, lenth_of_left_over_data);
	cleaned_buffer[lenth_of_left_over_data] = '\0';
	return (free(static_buffer), cleaned_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	static_buffer = read_to_static_buffer(fd, static_buffer, buff);
	if (!static_buffer)
		return (NULL);
	line = extract_line(static_buffer);
	if (!line)
		return (NULL);
	static_buffer = clean_static_buffer(static_buffer);
	return (line);
}
