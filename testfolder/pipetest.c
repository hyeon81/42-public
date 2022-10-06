#include <unistd.h>
#include <stdio.h>

#define MAXLINE 4096 /* max line length */

int main(void)
{
    int n, fd[2];
    pid_t pid; 
    char line[MAXLINE];

    if (pipe(fd) < 0) { //파이프 만들기? fd[0] = 3, fd[1] = 4 (추측)
        printf("pipe error \n");
        return(-1);
        /* err_sys("pipe error"); */
    }

    if ( (pid = fork()) < 0) { //fork로 자식 프로세스 만들기
        printf("fork error \n");
        return(-2);
        /* err_sys("fork error"); */

    } 
    //부모에서 쓰기
    else if (pid > 0) {
        printf("PARENT\n");
        close(fd[0]); //읽기전용 fd[0]을 닫고
        write(fd[1], "Hello world\n", 12); //쓰기전용 fd[1]에 쓴다. (wirte로)

    //자식에서 읽고 수행
    } else { 
        printf("CHILD\n");
        close(fd[1]); //쓰기전용 fd[1]을 닫고
        n = read(fd[0], line, MAXLINE); //읽기전용 fd[0]을 읽는다.
        write(STDOUT_FILENO, line, n); //읽자!
    }

    return(0);
}