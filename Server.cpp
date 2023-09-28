#include "Server.cpp"

Server::Server(std::string port, std::string password)
{
    this->password = password;
    this->port = convertPort(port);
}

~Server::Server()
{

}

int Server::runServer()
{
    const int PORT = 4242;
    const int BUFFER_SIZE = 1024;
    const int EVENTLIST_SIZE = 10;

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        perror("Socket creation failed");
        return -1;
    }
    sockaddr_in serverAddress; // serverAddress 구조체는 서버의 주소 정보를 설정
    memset(&serverAddress, 0, sizeof(serverAddress)); //이거 왜하는거지?

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
    fcntl(serverSocket, F_SETFL, O_NONBLOCK); //

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
    /*EV_SET(struct kevent *event, uintptr_t ident, short filter, u_short flags, u_int fflags, intptr_t data, void *udata);
        event: 이벤트 설정을 저장할 struct kevent 구조체에 대한 포인터입니다.
        ident: 이벤트를 연결할 파일 디스크립터, 소켓 디스크립터 또는 식별자입니다. 이 경우 serverSocket은 서버 소켓의 파일 디스크립터입니다.
        filter: 이벤트 필터를 나타냅니다. 이 예제에서는 EVFILT_READ를 사용하여 데이터 수신 이벤트를 나타냅니다. 이것은 데이터가 소켓으로부터 읽을 준비가 되었을 때 이벤트를 트리거합니다.
        flags: 이벤트 설정에 대한 플래그를 설정합니다. EV_ADD 플래그는 이벤트를 추가하고 활성화한다는 것을 나타냅니다. 이 플래그가 없으면 이벤트가 비활성화됩니다.
        fflags: 특정 이벤트 필터에 대한 추가적인 플래그입니다. 이 예제에서는 사용하지 않으므로 0으로 설정합니다.
        data: 이벤트와 관련된 데이터를 나타냅니다. 이 예제에서는 사용하지 않으므로 0으로 설정합니다.
        udata: 사용자 정의 데이터 포인터입니다. 이 예제에서는 사용하지 않으므로 NULL로 설정합니다.
    */
    // int kevent(int kq,
    //            const struct kevent *changelist,
    //            int nchanges,
    //            struct kevent *eventlist,
    //            int nevents,
    //            const struct timespec *timeout);
    struct kevent eventList[EVENTLIST_SIZE]; // 감시하는 놈들 중에서 문제아 발생 목록을 정리
    // kevent 함수를 사용하여 kqueue로부터 이벤트를 대기 이 코드에서는 서버 소켓의 읽기 이벤트를 모니터링하고 있음
    while (1)
    {
        // kqueue에 이벤트 첨부
        std::cout << "1" << std::endl;
        int nev = kevent(kq, &events[0], events.size(), eventList, EVENTLIST_SIZE, NULL); // kevent 함수를 사용하여 새 이벤트를 기다리거나 (클라이언트 연결 시도) 이전에 등록한 이벤트를 모니터링합니다.
        // kq로 전달된 kqueue에 새로 모니터링할 이벤트를 등록하고, 발생하여 아직 처리되지 않은(pending 상태인) 이벤트의 개수를 return
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
                // serverSocket에 대한 이벤트가 발생했다면, 새 클라이언트가 서버에 연결하려는 시도가 있음을 의미
                int clientSocket = accept(serverSocket, nullptr, nullptr);
                // 새로운 클라이언트 연결이 들어오면 accept를 통해 클라이언트 연결을 수락하고 새로운 클라이언트 소켓을 생성하고,
                if (clientSocket == -1)
                {
                    perror("Accepting client connection failed");
                    continue;
                }
                EV_SET(&event, clientSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
                events.push_back(event);
                std::cout << eventList[i].ident << " : connected" << std::endl;
                // 해당 클라이언트 소켓의 읽기 이벤트를 설정하고 활성화
                // 이 새로운 클라이언트 소켓을 모니터링 대상으로 추가하기 위해 EV_SET을 사용하여 새 이벤트를 이벤트 배열에 추가
            }
            else
            { // 이벤트가 serverSocket이나 연결 종료 이벤트가 아닌 경우에는 데이터를 읽고 에코하는 클라이언트와의 통신이 이루어진다
                int clientSocket = eventList[i].ident;
                char buffer[BUFFER_SIZE];
                int bytesRead;
                Client &client(clientSocket);
                // 클라이언트로부터 데이터를 수신하고, 그 데이터를 다시 클라이언트에게 전송
                while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0)
                {
                    //그러면 메시지 클래스 작성해놓은거 있잖음
                    //최대한 그걸 활용할건데
                    //유효성 검사를 어느 수준까지 할 것인가를 정해야함
                    //그럼 일단
                    //간단하게 해피케이스 먼저 보고 결정하자
                    //일단 가장 먼저 파싱할 때 중요한점
                    //구분자 결정
                    //그리고 데이터를 어떻게 넘겨줄 것인지
                    //이거부터 해보자
                    //[':' <prefix> <SPACE> ] <command> <params> <crlf>
                    // 이게 메시지 규약임
                    //대괄호 안에 있는게 생략 가능으로 앎
                    //https://ko.wikipedia.org/wiki/EBNF
                    //저 위의 문구를 해석 하기 위한 링크? BNF 표기법에 대한 링크임
                    //대괄호 안은 생략 가능
                    // 그러면 이제 command params crlf
                    // 이걸 먼저 구분해보자고
                    // ':' 콜론 이걸로 생략했는지 아니면 넣었는지 구분 가능함
                    // <letter> { <letter> }
                    // 이게 command임 근데 넘버 부분은 서버에서 보내줄 때만 이니까 무시해도 됨
                    // 그래서 letter (문자열) 만 보면 되고 특수문자든 뭐든 들어가있으면 오류 처리
                    // 그리고 다음 params
                    // <SPACE> [ ':' <trailing> | <middle> <params> ]
                    // 스페이스바가 없으면 파라미터가 안 들어왔다고 판단하고 command 부분으로 생각하면 됨
                    // 그래서 공백으로 다 구분하는거고
                    // ':' 이게 없으면 trailling 부분 생략 가능
                    // 그리고 middle 부분은 <Any *non-empty* sequence of octets not including SPACE or NUL or CR or LF, the first of which may not be ':'>
                    // 이렇게 써있는데 간단하게 말해서 공백, 널문자, CR, LF만 아니면 다 됨 인거야
                    // 말 그대로 중간문자라는건데
                    // 뭐 딱히 신경 안써도 되는게
                    // 예를 들어서
                    // PRVMSG jbak "fdsafdsafudosnafdskafbdsoafdls"
                    // 이런걸 보내려고 하는데 저걸 큰 따옴표로 묶어서 할 수도 있짢음?
                    // 이럴 때는 인자가 뭐든 들어올 수 있다는걸 얘기하는거임 걍
                    // 결론은 msg '공백' param crlf
                    // 으로 구분하는 것이고
                    // crlf가 안 들어왔으면 param일 수도 있으니까 아직 처리하면 안 되는 애고
                    // 여기까지가 message에 대한 정리임
                    // recv가 소켓의 한계치만큼만 받을 수 있는데
                    // 어떤 OS는 65535 - 패킷데이터
                    // 암튼 그래서 메시지가 잘려올 수도 있다
                    // 근데 사실 irc 클라-서버 에서는 500바이트 제한이 있어서 문제 없는데
                    // nc로 서버에 직접 데이터 보낼 때 저런 문제가 발생해서
                    // 이건 너 원하는대로 처리하면 됨
                    // 굳이 신경 안 써도 되고
                    // 있긴 했는데 저게 평가 내용인지는 모르겠음
                    // 서브젝트에서 이미 클라 정해서 하라고 했기 때문에..
                    // 암튼 이제 메시지를 파싱하는 부분으로 넘어가보자고


                    communicateClient(client);
                    //출력할 메세지 설정 필요
                    send(clientSocket, buffer, bytesRead, 0);
                    write(1, buffer, bytesRead); // 요청 데이터 출력
                }
                if (bytesRead == 0)
                {
                    close(clientSocket);
                    EV_SET(&event, clientSocket, EVFILT_READ, EV_DELETE, 0, 0, NULL);
                    events.push_back(event);
                    // 데이터가 더 이상 수신되지 않으면 클라이언트 소켓을 닫고, 해당 클라이언트 소켓의 읽기 이벤트를 EV_DELETE를 사용하여 제거
                    // 만약 클라이언트가 연결을 종료하면, 해당 클라이언트 소켓을 닫고 모니터링 대상에서 제거
                }
            }
        }
    }
    return 0;
}

void Server::tmpRunServer()
{
    int clientSocket = 10;
    std::string buffer = "PASS 0801"
    Client &client(clientSocket);

    client.setReadBuf(buffer);
    communicateClient(client);
}

void Server::communicateClient(Client &client)
{
    //버퍼를 읽어와서 실행한다.
    std::istringstream iss(client.getReadBuf());

    // 구분자로 문자열 나누기
    std::string token;
    char delimiter = "\r\n";

    while (std::getline(iss, token, delimiter))
    {
        Message msg(token);
        //구현에 따라 다른게 제일 키포인트임
        //뭐 예를 들어서
        //recv를 다 하고
        //한번더 했는데 recv의 리턴 값이 1 이상이다
        //그러면 내용이 더 남아있는 만큼 계속 읽을거잖아
        //그러면 recv가 여러번일 수도 있지
        //모든 메시지 파싱 책임을 message클래스에 넣을거면
        //이 구조는 바꿔야지ㅇㅇ
        //어차피 파싱이 완료된 애들(서버에서 처리해야할 것들)만 남아있을 거잖아
        //그럼 걍 doCommand(message) 이게 맞지
        //거기서 message.command 보고 message.params를 처리하면 되는거고
        //그 다음에는 그치 이제 날려야지
        //뭐 그건 서버니까 올 수도 있지
        //서버 입장에서는 항상 극한의 스트레스를 생각해야함
        //그래서 너가 걱정하는게 뭔지 알겠다고 말한거였음
        //그래서 클라이언트가 메시지 객체를 소유하는게 나을것 같냐고 물어본것도 그거임
        //ㅇㅇ 너무 비효율적이긴 해
        //몇 개의 클라이언트가 동시에 보내든 하나의 함수만 통과해서 가는거랑 똑같잖아
        //그러면 대기시간이 엄청 길어지겠지
        //그리고 crlf안 오면 메시지 들고있어야 하는데 이 때도 문제가 발생하고
        //클라이언트가 소유하는게 맞는듯
        //클라이언트가 보낸거고, 그 클라이언트에 대한 요청을 처리할거니까ㅇㅇ

        //ㅇㅇ 클라이언트가 요청 -> 서버에서 채널 만듦 -> 서버 응답 -> 클라이언트한테 결과 전송
        //클라이언트 join asdf -> 서버에서 채널 확인 -> asdf 없음 -> asdf 만듦 -> 클라이언트는 오퍼 -> 클라이언트한테 결과 전송
        //ㅇㅇ 


        MessageInfo cmd = msg.getMessageInfo();
        runCommand(cmd, client);
    }
}

void Server::addClient(Client &client)
{
    //PASS, NICK, USER 받기. 명령어 순서대로 안들어오면 어떡하지?
    //PASS 명령어
    //메세지는 커멘드를 런하는 애로 만들자 그냥 
    Server message(client, client.getBuf());

    client.setValid();
    this->clients.insert(make_pair(fd, client));
}

unsigned int Server::convertPort(std::string port)
{
    char *stopstring;
    int res;
    // for (unsigned int i = 0; i < port.length(); i++)
    // {
    //     //숫자가 맞는지 검증
    // }
    res = strtod(av[1], &stopstring);
    //오류 검증
    // if (res)
    //     throw std::runtime_error("Error: not a positive number");
    return (res);
}
