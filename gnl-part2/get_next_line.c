/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:31:21 by ktunchar          #+#    #+#             */
/*   Updated: 2022/12/03 18:11:36 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *buffer, int fd)
{
	char *line;
	char *next;
	int	n;


	line = NULL;
	if (ft_strlen(buffer))
	{
		next = ft_strchr(buffer, '\n');
		if (next)
		{
			*next = '\0';
			line = ft_strjoin(buffer, "\n");
			ft_buffercpy(buffer, next + 1);
			return (line);
		}
		line = ft_strjoin(buffer, "");
		*buffer = 0;
	}
	n = read(fd, buffer, BUFFER_SIZE);
	if (n >= 0)
		buffer[n] = '\0';
	if (n > 0 && !line)
		line = ft_strjoin("","");
	return (line);

 
}
	
char    *get_next_line(int fd)
{
    static char		*buffer;
    char			*line;
	char			*next;
	int	n;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!buffer) // there will go to the condition only the first time callin gnl function
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	next = read_line(buffer, fd);
	while (next != NULL)
	{
		
		if (line == NULL)
			line = next;
		else 
			line = ft_strjoin(line, next);	
		if (ft_strchr(line, '\n'))
			return (line);

		next = read_line(buffer, fd);
	}
	free(buffer);
	return (line);


}

int main()
{
	int fd;

	fd = open("test",O_RDONLY);
	if (fd < 0)
		printf("Cannot Open File\n");
	printf("line 1 :%s\n",get_next_line(fd));
	printf("line 2 :%s\n",get_next_line(fd));
    
}