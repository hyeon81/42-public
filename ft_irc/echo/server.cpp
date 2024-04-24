#include <sys/socket.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
        return (-1);
    }
    // 1. socket(): 리스닝 소켓 생성
    int server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1)
    {
        std::cout << "socker() error" << std::endl;
        return (-1);
    }

    //sockaddr_in은 소켓 주소의 틀을 형성해주는 구조체. AF_INET일 경우 사용
    // server_addr의 주소 정보를 초기화, IP주소와 포트 지정
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // IPv4 주소 체계 사용 
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // IP 주소 지정.  INADDR_ANY는 서버 자신의 IP주소
    server_addr.sin_port = htons(atoi(argv[1])); // 포트 번호 지정

    // 2. bind(): 소켓에 위에서 생성한 주소 정보 할당
    // 근데 왜 ip 주소 부분에 server_addr이 들어가는 거지?
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        std::cout << "bind() error" << std::endl;
        return (-1);
    }

    // 3. listen(): 소켓을 리스닝 상태로 변경
    if (listen(server_sock, 5) == -1) //동시 연결을 받는 최대 클라이언트 수.
    {
        std::cout << "listen() error" << std::endl;
        return (-1);
    }

    // 4. accept(): 클라이언트의 요청이 들어오면, 접속을 받는다
    // accept()함수 호출을 해서, 실제 데이터를 보낼 수 있는 소켓 생성
    struct sockaddr_in client_addr; //accept 함수에서 사용
    int client_addr_size = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr*)*client_addr, (socklen_t*)*client_addr_size);
    if (client_sock == -1)
    {
        std::cout << "accept() error" << std::endl;
        return (-1);
    }
    else
    {
        std::cout << "client accept" << std::endl;
    }

    // *5. close(): listen 중인 서버 측 소켓을 닫는다? (여기선 1개의 클라이언트만 받을거라)
    
    // *6. socket(): 데이터를 주고 받을 소켓 생성?

    // 7. read(): send/recv를 통해 데이터를 주고 받는다 (while문으로)

    // 8. write(): 데이터 전송?
    while (1)
    {
        char buffer[1024];
        int str_len = read(client_sock, buffer, 1023);
        buffer[str_len] = 0;
        std::cout << "Message from client: " << buffer << std::endl;
        std::string msg = "Hello World!";
        write(client_sock, msg.c_str(), msg.size());
        //어떻게 탈출? 그전까지는 그냥 받는다.
    }
    // std::string msg = "Hello World!";
    // write(client_sock, msg.c_str(), msg.size());
    // 9. read()
    // 10. close(): 클라이언트와 연결된 소켓을 닫는다
    close(client_sock);
    close(server_sock);
    return (0);
}