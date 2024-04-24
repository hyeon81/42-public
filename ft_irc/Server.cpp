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
    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        perror("Binding failed");
        return -1;
    }
    if (listen(serverSocket, 5) == -1)
    {
        perror("Listening failed");
        return -1;
    }
    fcntl(serverSocket, F_SETFL, O_NONBLOCK);
    std::cout << "Server listening on port " << PORT << std::endl;
    int kq = kqueue();
    if (kq == -1)
    {
        perror("kqueue initialization failed");
        return -1;
    }
    struct kevent event;
    std::vector<struct kevent> events;
    EV_SET(&event, serverSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
    events.push_back(event);
    struct kevent eventList[EVENTLIST_SIZE];
    while (1)
    {
        int nev = kevent(kq, &events[0], events.size(), eventList, EVENTLIST_SIZE, NULL);
        events.clear();
        if (nev == -1)
        {
            perror("kevent");
            return -1;
        }
        for (int i = 0; i < nev; i++)
        {
            if (eventList[i].flags & EV_EOF)
            {                        
                close(eventList[i].ident);
            }
            else if (eventList[i].ident == (uintptr_t)serverSocket)
            {
                int clientSocket = accept(serverSocket, nullptr, nullptr);
                if (clientSocket == -1)
                {
                    perror("Accepting client connection failed");
                    continue;
                }
                EV_SET(&event, clientSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
                events.push_back(event);
            }
            else if (eventList[i].filter == EVFILT_READ)
            { 
                int clientSocket = eventList[i].ident;
                char buffer[BUFFER_SIZE];
                int bytesRead;
                std::string buf = "";
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

