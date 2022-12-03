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

	
char    *get_next_line(int fd)
{
    static char		*buffer;
    char			*line;
	char			*next;
	int				n;

	if (!buffer)
		buffer = malloc(sizeof(char) *  (BUFFER_SIZE + 1));


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