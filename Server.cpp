#include "Server.hpp"

Server::Server(char *port, char *password)
{
    std::string pw(password);
    this->port = convertPort(port);
    this->password = pw;
    std::cout << "Server constructor port:" << this->port << " pw: " << this->password << std::endl;
}

Server::~Server()
{
}

int Server::runServer()
{
    const int PORT = this->port;
    const int BUFFER_SIZE = 1024;
    const int EVENTLIST_SIZE = 10;
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        perror("Socket creation failed");
        return -1;
    }
    sockaddr_in serverAddress; // serverAddress 구조체는 서버의 주소 정보를 설정
    memset(&serverAddress, 0, sizeof(serverAddress));
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
    fcntl(serverSocket, F_SETFL, O_NONBLOCK);
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
    // kevent 함수를 사용하여 kqueue로부터 이벤트를 대기 이 코드에서는 서버 소켓의 읽기 이벤트를 모니터링하고 있음
    while (1)
    {
        // kqueue에 이벤트 첨부
        int nev = kevent(kq, &events[0], events.size(), eventList, EVENTLIST_SIZE, NULL); // kevent 함수를 사용하여 새 이벤트를 기다리거나 (클라이언트 연결 시도) 이전에 등록한 이벤트를 모니터링합니다.
        // kq로 전달된 kqueue에 새로 모니터링할 이벤트를 등록하고, 발생하여 아직 처리되지 않은(pending 상태인) 이벤트의 개수를 return
        events.clear();
        if (nev == -1)
        {
            perror("kevent");
            return -1;
        }
        for (int i = 0; i < nev; i++)
        {
            // std::cout << "진입" << std::endl;
            if (eventList[i].flags & EV_EOF)
            {                        // 이벤트의 flags 필드를 검사하여 연결이 끊어졌는지 확인 EV_EOF 플래그를 사용하여 클라이언트 연결이 종료되었는지 확인
                close(eventList[i].ident); // 연결이 종료된 경우, 클라이언트 소켓을 닫고 해당 클라이언트에 대한 모니터링을 중지
            }
            else if (eventList[i].ident == (uintptr_t)serverSocket)
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
                // 해당 클라이언트 소켓의 읽기 이벤트를 설정하고 활성화
                // 이 새로운 클라이언트 소켓을 모니터링 대상으로 추가하기 위해 EV_SET을 사용하여 새 이벤트를 이벤트 배열에 추가
            }
            else if (eventList[i].filter == EVFILT_READ)
            { // 이벤트가 serverSocket이나 연결 종료 이벤트가 아닌 경우에는 데이터를 읽고 에코하는 클라이언트와의 통신이 이루어진다
                int clientSocket = eventList[i].ident;
                char buffer[BUFFER_SIZE];
                int bytesRead;
                std::string buf = "";
                /** 클라이언트 생성 **/
                // 클라이언트로부터 데이터를 수신하고, 그 데이터를 다시 클라이언트에게 전송
                memset(buffer, 0, sizeof(buffer));
                while ((bytesRead = recv(clientSocket, buffer , sizeof(buffer) - 1 , 0)) > 0)
                {
                    buffer[bytesRead] = '\0';
                    buf.append(buffer);
                    if (bytesRead < BUFFER_SIZE - 1)
                        break;
                }
                Udata *udata = new Udata();
                udata->buf = buf;
                struct kevent newEvent;
                EV_SET(&newEvent, clientSocket, EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, udata);
                events.push_back(newEvent);
            }
            else if (eventList[i].filter == EVFILT_WRITE)
            {
                int clientSocket = eventList[i].ident;
                Udata *tmp = static_cast<Udata *>(eventList[i].udata);
                communicateClient(clientSocket, tmp->buf);
                delete tmp;
            }
        }
    }
    return 0;
}

void Server::communicateClient(int fd, std::string buffer)
{
    /* 메세지 파싱.. */
    Client *client;
    
    if (nClients.find(fd) != nClients.end())
        client = nClients[fd];
    else
    {
        client = new Client(fd);
        nClients.insert(std::pair<int, Client *>(fd, client));
    }
    std::vector<MessageInfo> msgs;
    setMessageInfo(msgs, buffer);
    for (unsigned int i = 0; i < msgs.size(); i++)
    {
        if (client)
            runCommand(&msgs[i], client);
    }
}

void Server::runCommand(MessageInfo *msg, Client *client)
{
    try
    {
        void (Server::*funcs[14])(MessageInfo *msg, Client *client) = {&Server::pass, &Server::nick, &Server::user, &Server::join,
                                                                       &Server::part, &Server::topic, &Server::invite, &Server::kick, &Server::mode, 
                                                                       &Server::privmsg, &Server::ping, &Server::who, &Server::whois, &Server::quit};
        std::string cmds[14] = {"PASS", "NICK", "USER", "JOIN", "PART", "TOPIC", "INVITE", "KICK", "MODE", "PRIVMSG", "PING", "WHO", "WHOIS", "QUIT"};

        for (int i = 0; i < 14; i++)
        {
            if (cmds[i] == msg->cmd)
            {
                if (cmds[i] != "PASS" && client->getValid() == false)
                {
                    std::string errorMsg = ":ft_irc 451 :You have not registered";
                    sendResponse(errorMsg, client);
                    return;
                }
                if (cmds[i] != "PASS" && cmds[i] != "NICK" && cmds[i] != "USER" && (client->getNickname().empty() || client->getUsername().empty()))
                {
                    if (cmds[i] == "QUIT")
                    {
                        std::string responseMsg = "ERROR :CLosing link: (127.0.0.1) [Quit: leaving]";
                        sendResponse(responseMsg, client);
                        nClients.erase(client->getSocket());
                        delete client;
                        close(client->getSocket());
                        return;
                    }
                    std::string errorMsg = ":ft_irc 451 :You have not registered";
                    sendResponse(errorMsg, client);
                    return;
                }
                (this->*funcs[i])(msg, client);
                return;
            }
        }
    }
    catch (std::exception &e)
    {}
}

unsigned int Server::convertPort(char *port)
{
    char *stopstring;
    int res;

    res = strtod(port, &stopstring);
    // 오류 검증
    if (*stopstring != '\0')
        throw std::runtime_error("Error: not valid port number");
    if (res < 0 || res > 65535)
        throw std::runtime_error("Error: not valid port number");
    return (res);
}

void Server::setMessageInfo(std::vector<MessageInfo> &msg, std::string buf)
{
    std::string delimiter = "\r\n";
    size_t pos = 0;
    std::string rawMsgs;

    while ((pos = buf.find(delimiter)) != std::string::npos) {
        rawMsgs = buf.substr(0, pos);
        buf.erase(0, pos + delimiter.length());

        std::cout << "***rawMsgs: " << rawMsgs << std::endl;
        MessageInfo msgInfo;
        std::stringstream mss(rawMsgs);
        std::string cmd, param;
        mss >> cmd;
        msgInfo.cmd = cmd;
        while (mss >> param) {
            msgInfo.params.push_back(param);
        }
        msg.push_back(msgInfo);
    }
}

