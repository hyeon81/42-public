#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
    char test[2][30] = {"hello", "bye"};
    char res[30] = {0};
    int fd[2] = pipe(fd);
    int pid = fork();
    int status;
}