/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:49:21 by ktunchar          #+#    #+#             */
/*   Updated: 2022/11/01 19:32:15 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>


char	*create_buffer(char *buffer)
{
	char	*new_buffer;

	if (buffer != NULL)
		return (buffer);
	new_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (new_buffer != NULL)
		*new_buffer = '\0';
	return (new_buffer);
}


char	*read_line(int	fd,char *buffer)
{
	int		n;
	char	*next;
	char	*line
	if (fd < 0)
		return (NULL)
	n = read(fd, buffer, BUFFER_SIZE);
	if (n >= 0)
		*(buffer + n) = '\0';

}

char	*get_next_line(int fd)
{
	static char *buffer;
	char		*next;
	char		*line;

	buffer = create_buffer(buffer);

	next = NULL;

	line = read_line(fd, buffer);
}

int	main()
{

	get_next_line(1);
}