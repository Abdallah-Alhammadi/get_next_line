/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:17:49 by abalhamm          #+#    #+#             */
/*   Updated: 2023/02/19 23:25:45 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_buffer(int fd, char *buffer)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(buffer, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read_to_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line_get(buffer[fd]);
	buffer[fd] = ft_new_line(buffer[fd]);
	return (line);
}

int main()
{
	int	fd = open("text", O_RDONLY);
	int	fd1 = open("text.", O_RDONLY);
	int	fd2 = open("text", O_RDONLY);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", get_next_line(fd));
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", get_next_line(fd1));
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", get_next_line(fd2));
	}
}