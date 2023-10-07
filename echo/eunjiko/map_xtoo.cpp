#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/event.h>
#include <vector>
#include <fcntl.h>
#include <map>




const int PORT = 4242;
const int BUFFER_SIZE = 1024;
const int EVENTLIST_SIZE = 10;

int main() {
    // 서버 소켓 생성
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        return -1;
    }

    sockaddr_in serverAddress;
    // memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // 소켓과 서버 주소 바인딩
    // if (bind(serverSocket, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress)) == -1) {
    //     perror("Binding failed");
    //     return -1;
    // }

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Binding failed");
        return -1;
    }

    // 클라이언트 연결 대기
    if (listen(serverSocket, SOMAXCONN) == -1) {
        perror("Listening failed");
        return -1;
    }


    fcntl(serverSocket, F_SETFL, O_NONBLOCK); //

    std::cout << "Server listening on port " << PORT << std::endl;

    // kqueue 생성
    int kq = kqueue();
    if (kq == -1) {
        perror("kqueue initialization failed");
        return -1;
    }

    // 서버 소켓의 이벤트 설정
    struct kevent event;
    EV_SET(&event, serverSocket, EVFILT_READ, EV_ADD, 0, 0, nullptr);

    // 클라이언트 소켓을 관리하기 위한 map
    std::map<int, struct kevent> clientEvents;
    std::cout << "0000000000" << std::endl;

    // 서버 소켓 이벤트 등록
    if (kevent(kq, &event, 1, nullptr, 0, nullptr) == -1) {
        perror("Error registering server socket with kqueue");
        return -1;
    }

    while (true) {
        // kqueue에서 이벤트 대기
        std::cout << "진입" << std::endl;

        struct kevent eventList[EVENTLIST_SIZE];
        std::cout << "0진입" << std::endl;

        int nev = kevent(kq, nullptr, 0, eventList, EVENTLIST_SIZE, nullptr);
        std::cout << "1진입" << std::endl;

        if (nev == -1) {
            perror("kevent");
            return -1;
        }

        for (int i = 0; i < nev; i++) {
            std::cout << "2진입" << std::endl;
            if (eventList[i].flags & EV_EOF) {
                int closedSocket = eventList[i].ident;
                close(closedSocket);

                // 클라이언트 소켓 이벤트 제거
                if (clientEvents.find(closedSocket) != clientEvents.end()) {
                    struct kevent clientEvent = clientEvents[closedSocket];
                    kevent(kq, *clientEvent, 1, nullptr, 0, nullptr);
                    clientEvents.erase(closedSocket);
                }

                std::cout << closedSocket << " : closed connection" << std::endl;
            } else if (eventList[i].ident == serverSocket) {
                // 새 클라이언트 연결 수락
                int clientSocket = accept(serverSocket, nullptr, nullptr);
                if (clientSocket == -1) {
                    perror("Accepting client connection failed");
                    continue;
                }

                // 클라이언트 소켓의 읽기 이벤트 설정
                struct kevent clientEvent;
                EV_SET(*clientEvent, clientSocket, EVFILT_READ, EV_ADD, 0, 0, nullptr);

                // 클라이언트 소켓 이벤트 등록
                if (kevent(kq, *clientEvent, 1, nullptr, 0, nullptr) == -1) {
                    perror("Error registering client socket with kqueue");
                    close(clientSocket);
                } else {
                    // 클라이언트 소켓을 맵에 추가
                    clientEvents[clientSocket] = clientEvent;
                    std::cout << clientSocket << " : connected" << std::endl;
                }
            } else {
                // 클라이언트와 통신
                int clientSocket = eventList[i].ident;
                char buffer[BUFFER_SIZE];
                int bytesRead;

                // 클라이언트로부터 데이터 수신 후 에코
                while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
                    send(clientSocket, buffer, bytesRead, 0);
                    write(1, buffer, bytesRead); // 요청 데이터 출력
                }

                if (bytesRead == 0) {
                    // 클라이언트 연결 종료
                    close(clientSocket);

                    // 클라이언트 소켓 이벤트 제거
                    if (clientEvents.find(clientSocket) != clientEvents.end()) {
                        struct kevent clientEvent = clientEvents[clientSocket];
                        kevent(kq, *clientEvent, 1, nullptr, 0, nullptr);
                        clientEvents.erase(clientSocket);
                    }
                }
            }
        }
    }

    return 0;
}


/*
두 번째 코드에서의 문제는 클라이언트로부터 데이터를 읽을 때, 모든 클라이언트에 대한 데이터를 구분하지 않고 하나의 버퍼에 계속해서 덮어쓰고 있기 때문에 모든 클라이언트의 데이터를 처리하지 못하는 것입니다.

첫 번째 코드에서는 클라이언트 소켓과 관련된 데이터를 map<int, string> clients에 저장하고, 각 클라이언트의 소켓 식별자를 키로 사용하여 클라이언트마다 별도의 데이터를 관리합니다. 이렇게 하면 각 클라이언트의 데이터를 개별적으로 저장하고 관리할 수 있으며, 다수의 클라이언트에서 오는 메시지를 올바르게 처리할 수 있습니다.

두 번째 코드에서는 모든 클라이언트에 대한 데이터를 char buffer[BUFFER_SIZE];에 읽고 그대로 에코하고 있습니다. 그러므로 하나의 클라이언트에서 데이터를 보내면 그 데이터를 출력하고 에코합니다. 하지만 여러 클라이언트로부터 동시에 데이터가 오면 이 데이터들이 버퍼에 계속 덮어쓰여서 마지막 클라이언트의 데이터만 남게 됩니다.

두 번째 코드를 수정하여 각 클라이언트에 대한 데이터를 개별적으로 관리하도록 변경해야 합니다. 클라이언트 소켓 식별자와 해당 클라이언트의 데이터를 매핑하는 방식을 사용하면 됩니다. 이렇게 하면 각 클라이언트가 보낸 데이터를 개별적으로 처리할 수 있을 것입니다.
*/