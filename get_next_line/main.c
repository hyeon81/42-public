#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

int main() {
	char*	line1;
	char*	line2;
	int		fd1;
	int		fd2;
	int i = 1;
    int j = 1;

    if (!(fd1 = open("test.txt", O_RDONLY)) || !(fd2 = open("test2.txt", O_RDONLY)))
    {
    	printf("\nError in open");
        return (0);
    }
    printf("fd1: %d\n", fd1);
    printf("fd2: %d\n", fd2);
    while (i < 20)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
    	printf("Gnl %d line1 : %s\n", i++, line1);
        printf("Gnl %d line2 : %s\n", j++, line2);	
        free(line1);
        free(line2);
    }
	close(fd1);
	close(fd2);
	
    system("leaks a.out");
    printf("%ld", sysconf(_SC_OPEN_MAX));
    return (0);
}