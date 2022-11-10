/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:31:21 by ktunchar          #+#    #+#             */
/*   Updated: 2022/11/10 21:55:23 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

char    *get_next_line(int fd)
{
    char    *buffer
    char    
}

int main()
{
	int fd;

	fd = open("test",O_RDONLY);
	if (fd < 0)
		printf("Cannot Open File\n");
    
}