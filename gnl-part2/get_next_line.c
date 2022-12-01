/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:31:21 by ktunchar          #+#    #+#             */
/*   Updated: 2022/11/10 23:00:49 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
	
char    *get_next_line(int fd)
{
    static char		*buffer;
    char			*line;
	char			*next;
	int	n;

	line = NULL;
	if (!next)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!strchr(line, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (line = NULL)
			//strdup buffer to line;
		else
			//strcat buffer to line;
	}
	//cut only last \n in line
	//make buffer keep only after \n 
	return (line);


}

int main()
{
	int fd;

	fd = open("test",O_RDONLY);
	if (fd < 0)
		printf("Cannot Open File\n");
    
}