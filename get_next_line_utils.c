/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:29:30 by csouita           #+#    #+#             */
/*   Updated: 2024/01/09 18:47:28 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == s[i])
			return ((char *)(&s[i]));
	return (NULL);
}
size_t ft_strlen(const char *s)
{
	if (!s)
		return 0;
	size_t i ;
	i = 0 ;
	while (s[i])
		i++;
	return i ;
}
void *ft_memcpy(void *dest , const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *d;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == src)
		return dest;
	if (!dest && !src)
		return NULL;
	while (n--)
		*d++ = *s++;
	return dest;
}
char *ft_strjoin(char *s1 , char *s2)
{
	char *str;
	int ls1 ;
	int ls2 ;
	if (!s1)
		return (ft_strdup(s2));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = malloc(ls1 + ls2 * sizeof(char) + 1);
	if (!str)
		return NULL;
	ft_memcpy(str,s1,ls1);
	ft_memcpy(str + ls1,s2,ls2);
	str[ls1+ls2 + 1] = '\0';
	free(s1);
	return str;
}
char *ft_strdup(const char *s)
{
	char *str;
	str = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return NULL;
	ft_memcpy(str,s,ft_strlen(s));
	str[ft_strlen(s) + 1] = '\0';
	return str;
}


// int main ()
// {
// 	printf("%s",ft_strjoin("charaf","souita"));
// }



// #include <string.h>
// int main ()
// {
// 	char dest[20];
// 	char dest1[20];
// 	char *result = ft_memcpy(NULL,NULL,7);
// 	printf(" %s\n",(char *)result);
// // 	char *result1 = memcpy(NULL,NULL,7);
// // 	printf("%s",result1);
// }




// int main ()
// {
// 	printf("%d",ft_strlen("sihjh"));
// }