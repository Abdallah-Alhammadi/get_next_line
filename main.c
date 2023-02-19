#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	fd = open("text",O_RDONLY);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	line = get_next_line(fd);
	// printf("%s",line);
	while (line != NULL)
	{
		printf("%s",line);
		sleep(1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
			line = get_next_line(fd);
			printf("%s",line);
} 