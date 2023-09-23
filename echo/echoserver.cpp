#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/event.h>


const int PORT = 443;
const int BUFFER_SIZE = 1024;

int main() {
    // 소켓 생성, 그러나 아직 서버 소켓이 아님

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        return -1;
    }

    // 서버 주소 설정, 포트바인딩
    sockaddr_in serverAddress;
    // memset(&serv_addr, 0, sizeof(serv_addr)); 이거 왜하는거지?
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

    // 케이큐 초기화
    int kq = kqueue();
    if (kq == -1) {
        perror("kqueue initialization failed");
        return -1;
    }

    struct kevent events[2];
    EV_SET(&events[0], serverSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);

//     while (true) {
//         // 클라이언트 연결 수락
//         int clientSocket = accept(serverSocket, nullptr, nullptr);
//         if (clientSocket == -1) {
//             perror("Accepting client connection failed");
//             continue;
//         }

//         // 클라이언트와 통신
//         char buffer[BUFFER_SIZE]; 
//         int bytesRead;
//         //버퍼에 클라이언트가 보낸 데이터가 저장 된다
//         //얼만큼 읽었는지가 bytesread
//         //send로 버퍼에서 얼만큼 보낼지 지정하고 알려준다
//         //보내고 클로즈 그리고 다음 클라이언트를 기다림
//         while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
//             send(clientSocket, buffer, bytesRead, 0);
//         }

//         // 클라이언트 연결 종료
//         close(clientSocket);
//     }

//     // 서버 소켓 닫기
//     close(serverSocket);

//     return 0;
// }

    while (true) { // // kqueue를 사용하여 이벤트를 모니터링
        int nev = kevent(kq, events, 1, NULL, 0, NULL); 
        //kevent = 시스템 호출 이 호출은 이벤트를 모니터링하고 관리하는 데 사용된다
        //주로 이벤트 기반의 프로그래밍에서 다양한 이벤트(파일 디스크립터의 변화, 타이머 이벤트, 신호 등)를 감지하고 처리하는 데 사용
        //kevent 시스템 호출은 kqueue라는 이벤트 관리 메커니즘을 활용한다 이것은 특히 멀티플렉싱 및 비동기 I/O 작업에 유용하다
        //kqueue(이벤트 큐) 디스크립터
        // events: 이벤트 변경 목록을 나타내는 구조체 배열. 새로운 이벤트를 등록하거나 기존 이벤트를 수정 또는 삭제하는 데 사용
        //events 에 있는 변경 사항의 수 (이게 무슨 의미지)
        //nevents: eventlist에 저장할 수 있는 이벤트의 최대 수 (왜 0이지)
        if (nev == -1) {
            perror("kevent");
            return -1;
        }

        // events 배열에 이벤트가 등록 & EV_EOF 이벤트가 발생하면 서버 소켓이 종료
        if (events[0].flags & EV_EOF) {
        // 서버 소켓 닫고 프로그램 종료
            close(serverSocket);
            return 0;
        } 
        // events[0].ident는 소켓 식별자
        else if (events[0].ident == serverSocket) {
        // 새 클라이언트 연결 수락
            int clientSocket = accept(serverSocket, nullptr, nullptr);
            if (clientSocket == -1) {
                perror("Accepting client connection failed");
                continue;
            }
            // 새 연결된 클라이언트 소켓의 이벤트 등록
            EV_SET(&events[1], clientSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
        } 
        else {
        // 클라이언트와 통신
            int clientSocket = events[0].ident;
            char buffer[BUFFER_SIZE];
            int bytesRead;
            while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
                // 클라이언트로부터 데이터를 읽어서 다시 클라이언트에게 전송
                send(clientSocket, buffer, bytesRead, 0);
            }
            if (bytesRead == 0) {
            // 클라이언트 연결 종료
            // 클라이언트 소켓을 닫고 이벤트를 제거
                close(clientSocket);
                EV_SET(&events[1], clientSocket, EVFILT_READ, EV_DELETE, 0, 0, NULL);
            }
        }
    }
    return 0;
}