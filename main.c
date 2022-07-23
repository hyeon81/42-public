#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

int main() {
	char*	line;
	int		fd;
	int i = 1;
    
    if (!(fd = open("test.txt", O_RDONLY)))
    {
    	printf("\nError in open");
        return (0);
    }
	line = get_next_line(fd);
    while (line)
    {
    	printf("Gnl %d line : %s", i++, line);	
        free(line);	
    }
    printf("\n");
    
    free(line);
	close(fd);
	
    return (0);
}
