/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:49:03 by csouita           #+#    #+#             */
/*   Updated: 2024/01/26 15:44:29 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char	*get_read(char *save_str, int fd)
// {
// 	char	*buffer;
// 	ssize_t	read_n;

// 	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
// 	if (!buffer)
// 	{
// 		free(save_str);
// 		return (NULL);
// 	}
// 	read_n = 1;
// 	while (!ft_strchr(save_str, '\n'))
// 	{
// 		read_n = read(fd, buffer, BUFFER_SIZE);
// 		if (read_n <= 0)
// 			break ;
// 		buffer[read_n] = '\0';
// 		save_str = ft_strjoin(save_str, buffer);
// 	}
// 	free(buffer);
// 	if (read_n < 0)
// 	{
// 		free(save_str);
// 		return (NULL);
// 	}
// 	return (save_str);
// }

// char	*get_line(char *save_str)
// {
// 	size_t	i;
// 	char	*line;

// 	i = 0;
// 	if (!save_str[i])
// 	{
// 		free(save_str);
// 		return (NULL);
// 	}
// 	while (save_str[i] != '\n' && save_str[i])
// 		i++;
// 	if (save_str[i] == '\n')
// 		i++;
// 	line = malloc(i + 1);
// 	if (!line)
// 	{
// 		free(save_str);
// 		return (NULL);
// 	}
// 	ft_memcpy(line, save_str, i);
// 	line[i] = '\0';
// 	return (line);
// }

// char	*left_lines(char *line, char *save_str)
// {
// 	int		i;
// 	int		j;
// 	char	*new_save_str;

// 	i = 0;
// 	j = 0;
// 	while (save_str[i] == line[i] && save_str[i] && line[i])
// 		i++;
// 	if (!save_str[i])
// 	{
// 		free(save_str);
// 		return (NULL);
// 	}
// 	new_save_str = malloc(ft_strlen(save_str) - i + 1);
// 	if (!new_save_str)
// 	{
// 		free(save_str);
// 		return (NULL);
// 	}
// 	while (save_str[i])
// 		new_save_str[j++] = save_str[i++];
// 	new_save_str[j] = '\0';
// 	free(save_str);
// 	return (new_save_str);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*save_str;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	save_str = get_read(save_str, fd);
// 	if (!save_str)
// 		return (NULL);
// 	line = get_line(save_str);
// 	if (!line)
// 		return (NULL);
// 	save_str = left_lines(line, save_str);
// 	return (line);
// }
#include "get_next_line.h"

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
	if (!*saved_s)
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
	free(line);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*saved_s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	saved_s = all_buffer(saved_s, fd);
	if (!saved_s)
		return (NULL);
	line = get_line(saved_s);
	if (!line)
		return (NULL);
	saved_s = left_line(saved_s, line);
	return (line);
}

