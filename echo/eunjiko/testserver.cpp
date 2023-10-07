#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/event.h>
#include <vector>
const int PORT = 4242;
const int BUFFER_SIZE = 1024;
const int EVENTLIST_SIZE = 10;
int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        perror("Socket creation failed");
        return -1;
    }
    sockaddr_in serverAddress; // serverAddress 구조체는 서버의 주소 정보를 설정
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    // 소켓과 서버 주소를 바인딩
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        perror("Binding failed");
        return -1;
    }
    // 함수를 사용하여 클라이언트의 연결을 대기
    if (listen(serverSocket, 5) == -1) // 5보다는 SOMAXCONN을 일단 추천
    {
        perror("Listening failed");
        return -1;
    }
    std::cout << "Server listening on port " << PORT << std::endl;
    // kqueue 생성
    int kq = kqueue(); // kqueue를 초기화하고 커널에 새로운 event queue를 만들고 큐의 디스크립터를 얻음
    // 리턴된 fd는 kevent()에서 이벤트를 등록, 모니터링하는데 사용
    if (kq == -1)
    {
        perror("kqueue initialization failed");
        return -1;
    }
    struct kevent event;
    std::vector<struct kevent> events; // 감시해야할 목록 리스트
    // kevent 구조를 초기화
    EV_SET(&event, serverSocket, EVFILT_READ, EV_ADD, 0, 0, NULL); // struct kevent 배열인 events를 사용하여 EV_SET 함수를 호출하여 서버 소켓의 읽기 이벤트를 설정하고 활성화
    // EV_SET 매크로는 kqueue의 이벤트를 설정하고 구성하기 위한 함수 이 함수를 사용해 kqueue의 이벤트 필터, 이벤트 액션 및 관련 정보를 설정할 수 있다
    events.push_back(event);
    struct kevent eventList[EVENTLIST_SIZE]; // 감시하는 놈들 중에서 문제아 발생 목록을 정리
    while (1)
    {
        std::cout << "1" << std::endl;
        int nev = kevent(kq, &events[0], events.size(), eventList, EVENTLIST_SIZE, NULL); // kevent 함수를 사용하여 새 이벤트를 기다리거나 (클라이언트 연결 시도) 이전에 등록한 이벤트를 모니터링합니다.
        std::cout << "nev = " << nev << std::endl;
        if (nev == -1)
        {
            perror("kevent");
            return -1;
        }
        for (int i = 0; i < nev; i++)
        {
            std::cout << "진입" << std::endl;
            if (eventList[i].flags & EV_EOF)
            {                        // 이벤트의 flags 필드를 검사하여 연결이 끊어졌는지 확인 EV_EOF 플래그를 사용하여 클라이언트 연결이 종료되었는지 확인
                close(serverSocket); // 연결이 종료된 경우, 클라이언트 소켓을 닫고 해당 클라이언트에 대한 모니터링을 중지
                std::cout << eventList[i].ident << " : closed connection" << std::endl;
                return 0;
            }
            else if (eventList[i].ident == serverSocket)
            { // ident 필드를 사용하여 이벤트가 발생한 소켓을 확인
                int clientSocket = accept(serverSocket, nullptr, nullptr);
                if (clientSocket == -1)
                {
                    perror("Accepting client connection failed");
                    continue;
                }
                EV_SET(&event, clientSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
                events.push_back(event);
                std::cout << eventList[i].ident << " : connected" << std::endl;
            }
            else
            { // 이벤트가 serverSocket이나 연결 종료 이벤트가 아닌 경우에는 데이터를 읽고 에코하는 클라이언트와의 통신이 이루어진다
                int clientSocket = eventList[i].ident;
                char buffer[BUFFER_SIZE];
                int bytesRead;
                while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0)
                {
                    send(clientSocket, buffer, bytesRead, 0);
                    write(1, buffer, bytesRead); // 요청 데이터 출력
                }
                if (bytesRead == 0)
                {
                    close(clientSocket);
                    EV_SET(&event, clientSocket, EVFILT_READ, EV_DELETE, 0, 0, NULL);
                    events.push_back(event);
                }
            }
        }
    }
    return 0;
}