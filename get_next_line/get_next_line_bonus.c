/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:10:06 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/01 18:36:10 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*update_stash(char **stash)
{
	char	*content_read;
	char	*temp_stash;
	int		i;

	i = 0;
	temp_stash = ft_strdup(*stash);
	if (temp_stash == NULL)
		return (NULL);
	while (temp_stash[i] != '\0' && temp_stash[i] != '\n')
		i++;
	if (temp_stash[i] != '\0' && temp_stash[i] == '\n')
		i++;
	content_read = ft_substr(temp_stash, 0, i);
	if (content_read == NULL)
		return (free(temp_stash), NULL);
	free(*stash);
	*stash = ft_substr(temp_stash, i, ft_strlen(temp_stash));
	free(temp_stash);
	if (*stash == NULL)
		return (free(content_read), NULL);
	if (content_read[0] == '\0')
		return (free(content_read), NULL);
	return (content_read);
}

static char	*read_line(int fd, char **stash)
{
	char	*content_buffer;
	char	*temp;
	int		read_byte;

	content_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (content_buffer == NULL)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, content_buffer, BUFFER_SIZE);
		if (read_byte < 0)
			return (free(content_buffer), NULL);
		content_buffer[read_byte] = '\0';
		temp = *stash;
		*stash = ft_strjoin(temp, content_buffer);
		free(temp);
		if (*stash == NULL)
			return (free(content_buffer), NULL);
		if (ft_strchr(*stash, '\n') || read_byte == 0)
			return (free(content_buffer), update_stash(stash));
	}
	free(content_buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash[1023];
	char		*buffer;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd] == NULL)
	{
		stash[fd] = ft_strdup("");
		if (stash[fd] == NULL)
			return (NULL);
	}
	if (ft_strchr(stash[fd], '\n'))
	{
		buffer = update_stash(&stash[fd]);
		if (buffer == NULL)
			return (free(stash[fd]), stash[fd] = NULL, NULL);
		return (buffer);
	}
	buffer = read_line(fd, &stash[fd]);
	if (buffer == NULL)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	return (buffer);
}
