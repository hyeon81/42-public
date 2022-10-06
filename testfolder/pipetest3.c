#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main (int argc, char *argv[], char **envp)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        fprintf(stderr, "pipe error: %s\n", strerror(errno));
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        return 1;
    }

    //자식 프로세서가 처리하는 코드
    if (pid == 0)
    {
        //표준 출력을 파이프의 쓰는 쪽으로 설정
        dup2(fd[1], 1); //새서술자의 값을 fd2로 지정
        close(fd[0]);
        char *arg[] = {"ls", (char *)0};
        printf("Running ls with execve\n");
        /* 첫 번째 인수가 경로 이름이고 명령라인 인수는 인수들의 배열. 환경 변수 넘겨 줌 */
        int ste = execve("/bin/ls", arg, envp);
        if (ste == -1)
        {
            fprintf(stderr, "run error: %s\n", strerror(errno));
            return 1;
        }
    }
    else {        
        //부모 프로세스만 여기에 도달한다
        //표준 입력을 파이프의 읽는 쪽으로 리다이렉션한다.
        dup2(fd[0], 0);
        close(fd[1]);
        char line[255];
        while (fgets(line, sizeof(line), stdin) != 0)
            printf("%s", line);
    }  
    return 0;
}