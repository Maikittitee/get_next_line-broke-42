/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:31:21 by ktunchar          #+#    #+#             */
/*   Updated: 2022/12/03 21:47:28 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *buffer, int fd)	
{
	char	*next;
	char	*line;
	int		n;

	line = NULL;
	n = read(fd, buffer, BUFFER_SIZE);
	while (ft_strlen(buffer)) //if not EOF
	{
		next = ft_strchr(buffer, '\n');
		if (next == NULL)
			line = ft_strjoin(buffer, "");
		else
		{
			line = ft_strjoin(buffer, "\n");
			ft_buffercpy(buffer, next + 1);
			//printf("line is %s\n",line);
			return (line);
		}
	}
}
	
char    *get_next_line(int fd)
{
    static char		*buffer;
    char			*line;
	char			*next;
	int				n;

	if (!buffer)
		buffer = malloc(sizeof(char) *  (BUFFER_SIZE + 1));
	next = read_line(buffer, fd);
	if (ft_strchr(next,'\n'))
		return (next);



}

int main()
{
	int fd;

	fd = open("test",O_RDONLY);
	if (fd < 0)
		printf("Cannot Open File\n");
	printf("line 1 :%s\n",get_next_line(fd));
	// printf("line 2 :%s\n",get_next_line(fd));
    
}