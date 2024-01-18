/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:49:03 by csouita           #+#    #+#             */
/*   Updated: 2024/01/18 16:53:08 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_read(char *saved_s ,int fd)
{
    char *buffer;
    ssize_t read_n;

    buffer = malloc(BUFFER_SIZE * sizeof(char) +1);
    if (!buffer)
    {
        free(saved_s);
        return NULL;
    }
    read_n = 1;
    while (!ft_strchr(saved_s,'\n'))
    {
        read_n = read(fd, buffer,BUFFER_SIZE);
        if (read_n <= 0)
            break;
        saved_s[read_n] = '\0' ;
        saved_s = ft_strjoin(saved_s,buffer);
    }
    free(buffer);
    if ( read_n < 0)
    {
        free(saved_s);
        return NULL;
    }
    return saved_s;
}

char *get_line(char *saved_s)
{
    char *line;
    size_t i;
    i = 0 ;
    if (!saved_s)
    {
        free(saved_s);
        return NULL;
    }
    while (saved_s[i] != '\n' && saved_s[i])
        i++;
    if (saved_s[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
    {
        free(saved_s);
        return NULL;
    }
    line[i + 1] = '\0';
    ft_memcpy(line ,saved_s,i);
    return line;
}
char *left_line(char *saved_s, char *line)
{
    size_t i;
    size_t j;
    char *new_str;
    i = 0;
    j = 0;
    while (saved_s[i] == line[i] && saved_s[i] && line[i])
        i++;
    if (!saved_s[i])
    {
        free(saved_s);
        return NULL;
    }
    new_str = malloc(ft_strlen(saved_s) -i + 1);
    if (!new_str)
    {
        free(saved_s);
        return NULL;
    }
    while (saved_s[i])
        new_str[j++]=saved_s[i++];
        new_str[j] = '\0';
        free(saved_s) ;
    return new_str;
}
