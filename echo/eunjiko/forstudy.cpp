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
    // TCP 소켓 생성(대기 소켓), 아직은 서버 소켓이 아님

 
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        return -1;
    }

    // 서버 주소 설정, 포트바인딩


    sockaddr_in serverAddress;  //서버 주소 정보를 설정하기 위한  sockaddr_in 구조체를 선언
    // memset(&serv_addr, 0, sizeof(serv_addr)); 이거 왜하는거지?
    serverAddress.sin_family = AF_INET; // 주소 체계를 IPv4로 설정
    serverAddress.sin_addr.s_addr = INADDR_ANY; // 모든 네트워크 인터페이스에서 클라이언트의 연결을 받아들이도록 설정
    serverAddress.sin_port = htons(PORT); // 서버가 대기할 포트 번호 설정 

    // 소켓 바인딩 -> 소켓을 포트와 연결시켜준다 클라이언트의 데이터가 에코서버로 가는 길을 알려줌


    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        //서버 소켓을 지정한 IP 주소와 포트에 바인딩 이렇게 하면 클라이언트가 해당 IP주소와 포트로 서버에 연결할 수 있음
        //왜?
        perror("Binding failed");
        return -1;
    }

    // 클라이언트 연결 대기


    if (listen(serverSocket, 5) == -1) {
        //listen함수를 호출하여 클라이언트 연결 요청을 수신할 수 있도록 서버 소켓을 설정
        //최대 5개의 대기중인 연결 요청을 처리할 수 있도록 설정
        perror("Listening failed");
        return -1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    //케이큐 초기화 케이큐 디스크립터 생성

    //이벤트 큐를 초기화 한다는게 뭘 의미할까
    int kq = kqueue(); //이벤트 큐의 fd를 리턴
    if (kq == -1) {
        perror("kqueue initialization failed");
        return -1;
    }
    //kqueue()는 커널에 새로운 event queue를 만들고, 그것의 fd를 return 
    //큐 생성 커널에 공간 생성
    //return된 fd는 후술할 kevent()에서 이벤트를 등록, 모니터링하는데 사용 / 이 queue는 fork(2)로 자식 프로세스 분기 시 상속되지 않는다?



    struct kevent events[2]; //설정할 kevent 배열 각각 서버와 클라이언트
    /*서버소켓이벤트 : 클라이언트의 연결을 수락하기위한 이벤트를 모니터링한다 클라이언트가 연결을 시도하면
    서버소켓은 이벤트를 감지하고 새 클라이언트의 연결을 수락한다*/
    /*클라이언트소켓이벤트 : 각 클라이언트 소켓은 그 자체의 이벤트를 가지고 있으며, 클라이언트 소켓의 
    데이터 송수신을 관리한다. 즉 서버는 여러 클라이언트와 동시에 연결되어 있는 각 클라이언트의 소켓을 모니터링하고
    각 클라이언트로부터 데이터를 읽어 에코하는 등의 작업을 수행*/




    //케이큐 등록 / 이벤트 설정
    //서버소켓을 모니터링할건데 읽는 종류의 이벤트를 모니터링 할거다 라고 설정
    EV_SET(&events[0], serverSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
    //EV_SET함수를 사용하여 서버 소켓의 읽기 이벤트를 설정하고 활성화
    //이벤트를 모니터링할 파일 디스크립터(serverSocket)와 이벤트 종류(EVFILT_READ)를 지정
    //serverSoket 이벤트가 발생한 대상을 식별하는 식별자
    //이벤트 필터 어떤 종류의 이벤트를 모니터링할지 (읽기 가능한 데이터를 모니터링)
    //이벤트 설정에 대한 플래그 이벤트의 특성을 지정 (이벤트를 모니터링 대상으로 추가(활성화하겠다는뜻) 반대로는 제거)


    //무한 루프를 시작하여 클라이언트의 연결 및 데이터 송수신을 처리
    while (true) { // // kqueue를 사용하여 이벤트를 모니터링

        //실제로 모니터링을 하는 함수, 발생하여 아직 처리되지 않은 이벤트의 개수를 리턴
        //케이큐에서 발생한 이벤트를 기다리고 관리하는 부분 kevent함수를 통해 이벤트를 모니터링하고 처리
        //함수를 호출하여 이벤트 큐에서 이벤트를 대기하고 처리
        //새로운 클라이언트 연결을 대기하거나 이전에 등록한 이벤트를 모니터링
        int nev = kevent(kq, events, 1, NULL, 0, NULL);  //서버와 클라이언트 모두 모니터링중
        //timeout이 0이면 돌면서 noevent가 계속 뜨는거고
        //null로 처리하면 대기하고 있다가 발생하는 순간 밑으로 내려감



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


        // event의 flags필드를 검사하여 서버 소켓의 연결 종료 여부를 확인하고, 연결이 종료되면
        if (events[0].flags & EV_EOF) {
        // 서버 소켓 닫고 프로그램 종료
            close(serverSocket);
            return 0;
        } 
        // events[0].ident는 소켓 식별자
        //새로운 클라이언트의 연결 시도를 처리 accept함수를 사용하여 클라이언트의 연결을 수락하고, 새로운 클라이언트 소켓 생성
        else if (events[0].ident == serverSocket) {
        //events[0]의 ident는 늘 serverSocket이지만 가독성을 위해
        /* events의 첫번쨰 이벤트가 서버소켓과 관련있는지를 확인
        ident는 식별자 그러니까 식별자가 serverSocket인지 
        현재 처리중인 이벤트가 서버소켓과 관련이 있는지 검사
        관련이 있다면 이것은 새로운 클라이언트가 연결을 시도하려는 시점이라는것
        따라서 연결을 수락하고 클라이언트 소켓에 대한 새로운 읽기 이벤트를 설정하고 활성화
        */
        // 새 클라이언트 연결 수락
            int clientSocket = accept(serverSocket, nullptr, nullptr);
            if (clientSocket == -1) {
                perror("Accepting client connection failed");
                continue;
            }
            // 새 연결된 클라이언트 소켓의 이벤트 등록
            EV_SET(&events[1], clientSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
        } 

        //클라이언트와의 실제 통신을 처리
        else {
        // 클라이언트와 통신

            int clientSocket = events[0].ident;
            char buffer[BUFFER_SIZE];
            int bytesRead;
            //버퍼에 클라이언트가 보낸 데이터가 저장 된다
            //얼만큼 읽었는지가 bytesread
            //send로 버퍼에서 얼만큼 보낼지 지정하고 알려준다
            //보내고 클로즈 그리고 다음 클라이언트를 기다림
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