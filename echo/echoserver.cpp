#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

const int PORT = 443;
const int BUFFER_SIZE = 1024;

int main() {
    // 소켓 생성, 그러나 아직 서버 소켓이 아님
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    //에러처리
    if (serverSocket == -1) {
        perror("Socket creation failed");
        return -1;
    }
    // 서버 주소 설정
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // 소켓 바인딩 -> 소켓을 포트와 연결시켜준다
    // 클라이언트의 데이터가 에코서버로 가는 길을 알려줌
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Binding failed");
        return -1;
    }

    // 클라이언트 연결 대기
    if (listen(serverSocket, 5) == -1) {
        perror("Listening failed");
        return -1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    while (true) {
        // 클라이언트 연결 수락
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            perror("Accepting client connection failed");
            continue;
        }

        // 클라이언트와 통신
        char buffer[BUFFER_SIZE]; 
        int bytesRead;
        //버퍼에 클라이언트가 보낸 데이터가 저장 된다
        //얼만큼 읽었는지가 bytesread
        //send로 버퍼에서 얼만큼 보낼지 지정하고 알려준다
        //보내고 클로즈 그리고 다음 클라이언트를 기다림
        while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
            send(clientSocket, buffer, bytesRead, 0);
        }

        // 클라이언트 연결 종료
        close(clientSocket);
    }

    // 서버 소켓 닫기
    close(serverSocket);

    return 0;
}