/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maikittitee <maikittitee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:49:21 by ktunchar          #+#    #+#             */
/*   Updated: 2022/11/02 04:12:42 by maikittitee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
	char	*line;
	if (fd < 0)
		return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	if (n >= 0)
		*(buffer + n) = '\0';

}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*next;
	char		*line = "";
	int			n;

	buffer = create_buffer(buffer);
	if (!buffer)
		return (NULL);

	n = read(fd, buffer, BUFFER_SIZE);
	buffer[n] = '\0';

	next = ft_strchr(buffer, '\n');
	if (!next)
		line = ft_strjoin(line,buffer);


	return (line);


}

int	main()
{
	int	fd;

	fd = open("test",O_RDONLY);

	printf("gnl = %s\n",get_next_line(fd));
}
