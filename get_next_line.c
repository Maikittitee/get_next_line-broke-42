#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		i;
	int		j;

	//if (!s1 || !s2)
	//	return (NULL);
	buffer = malloc((strlen(s1) + strlen(s2) + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	bzero(buffer, strlen(s1) + strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[j])
		buffer[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buffer[i++] = s2[j++];
	return (buffer);
}

int	last_is_enter(char *str)
{
	int	len;

	len = strlen(str);

	if (str[len - 1] == '\n')
	{
		return (1);
	}
	return (0);
}


int	main()
{
	int fd;

	char *buffer;
	int	i;
	char *str = "";

	i = 1;

	fd = open("test",O_RDWR);

	printf("fd : %d\n",fd);

	while (!last_is_enter(buffer))
	{
		read(fd, buffer, 1);
		str = ft_strjoin(str,buffer);
	}

	
	printf("buffer : %s\n",str);
	
	//read(fd, buffer, 1);

	//printf("buffer : %s\n",buffer);
}
