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
	// line = get_next_line(fd);
    // printf("Gnl %d line : %s\n", i++, line);
    // free(line);	
    // line = get_next_line(fd);
    // printf("Gnl %d line : %s\n", i++, line);
    // free(line);	
    // line = get_next_line(fd);
    // printf("Gnl %d line : %s\n", i++, line);
    // free(line);	
    
    while ((line = get_next_line(fd)))
    {
    	printf("Gnl %d line : %s\n", i++, line);	
        free(line);	
    }
    // printf("finished\n");
    printf("Gnl %d line : %s\n", i++, line);	
    
    free(line);
	close(fd);
	
    return (0);
}
