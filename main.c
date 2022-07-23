#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"
char *get_next_line(int fd);
int main()
{
	int             fd;
	// int             i;
	int             j;
	char    		*line = 0;
	// char			*lineadress[66];

	j = 1;
	if (!(fd = open("check.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while (get_next_line(fd) != 0)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		// lineadress[j - 1] = line;
		// j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);

	// while (--j > 0)
		// free(lineadress[j - 1]);

	return (0);
}
