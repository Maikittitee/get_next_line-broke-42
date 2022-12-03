/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:49:14 by ktunchar          #+#    #+#             */
/*   Updated: 2022/12/03 21:30:05 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;

	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return (str + i);
	if (c == '\0')
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	buffer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[j])
		buffer[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buffer[i++] = s2[j++];
	return (buffer);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_buffercpy(char *dst, const char *src)
{
    while (*src)
    {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = 0;
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	buffer;

	buffer = ft_strjoin(s1, s2);
	free(s2);
	free(s1);
	return (buffer);
}