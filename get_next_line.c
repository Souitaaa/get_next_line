/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:49:03 by csouita           #+#    #+#             */
/*   Updated: 2024/01/09 21:53:50 by csouita          ###   ########.fr       */
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