/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:30:04 by csouita           #+#    #+#             */
/*   Updated: 2024/01/09 18:55:33 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12

char	*ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
void *ft_memcpy(void *dest , const void *src, size_t n);
char *ft_strjoin(char *s1 , char *s2);
char *ft_strdup(const char *s);


#endif 