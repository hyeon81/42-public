#include <sys/socket.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <cstdlib> 

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <IP> <port>" << std::endl;
        return (-1);
    }

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        std::cout << "socket() error" << std::endl;
        return (-1);
    }

    // 주소 정보를 초기화
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // IPv4 주소 체계 사용
    server_addr.sin_addr.s_addr = inet_addr(argv[1]); // IP 주소 지정
    server_addr.sin_port = htons(atoi(argv[2])); // 포트 번호 지정

    // 2. connect(): 서버의 주소 정보로, 서버에 연결 요청
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        std::cout << "connect() error" << std::endl;
        return (-1);
    } else
    {
        std::cout << "server connect" << std::endl;
    }

    std::string message;
    // 3. read()/write(): 서버와 데이터 송수신
    while (true)
    {
        std::cout << "Input message (Q to quit): ";
        std::getline(std::cin, message);
        if (message == "q" || message == "Q")
            break;
        write(sock, message.c_str(), message.size());
        // 버퍼에 저장된 데이터를 읽어서 str_len에 저장
        char buffer[1024];
        int str_len = read(sock, buffer, sizeof(buffer) - 1);
        if (str_len == -1)
        {
            std::cout << "read() error" << std::endl;
            break;
        }
        buffer[str_len] = '\0';
        std::cout << "Message from server: " << buffer << std::endl;
    }

    close(sock);
    return 0;
}
