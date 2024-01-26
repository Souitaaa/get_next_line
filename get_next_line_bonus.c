/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:33:46 by csouita           #+#    #+#             */
/*   Updated: 2024/01/26 15:40:59 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*all_buffer(char *str, int fd)
{
	char	*buffer;
	int		count;

	count = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (free(str), free(buffer), NULL);
		if (count == 0)
			break ;
		buffer[count] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (free(buffer), str);
}

char	*get_line(char *saved_s)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!saved_s[i])
	{
		free(saved_s);
		return (NULL);
	}
	while (saved_s[i] != '\n' && saved_s[i])
		i++;
	if (saved_s[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(saved_s);
		return (NULL);
	}
	line[i] = '\0';
	ft_memcpy(line, saved_s, i);
	return (line);
}

char	*left_line(char *saved_s, char *line)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	while (saved_s[i] == line[i] && saved_s[i] && line[i])
		i++;
	if (!saved_s[i])
	{
		free(saved_s);
		return (NULL);
	}
	new_str = malloc(ft_strlen(saved_s) - i + 1);
	if (!new_str)
	{
		free(saved_s);
		return (NULL);
	}
	while (saved_s[i])
		new_str[j++] = saved_s[i++];
	new_str[j] = '\0';
	free(saved_s);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*saved_s[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_s[fd] = all_buffer(saved_s[fd], fd);
	if (!saved_s[fd])
		return (NULL);
	line = get_line(saved_s[fd]);
	if (!line)
		return (NULL);
	saved_s[fd] = left_line(saved_s[fd], line);
	return (line);
}
