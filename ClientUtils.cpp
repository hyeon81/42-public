#include "Server.hpp"

void Server::addClientToServer(Client *client)
{
    if (client->getValid())
    {
        std::cout << "add client" << std::endl;
        this->clients.insert(std::make_pair(client->getSocket(), client));
    }
}

Client *Server::getClient(std::string nickname)
{
    std::cout << "Server getClient" << std::endl;
    std::map<int, Client*>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        if ((iter->second)->getNickname() == nickname)
            return (iter->second);
    }
    //유저가 존재하지 않음
    std::cout << "no such client" << std::endl;
    return (NULL);
}

bool Server::isExistClient(std::string nickname)
{
    std::cout << "Server isExistClient" << std::endl;
    std::map<int, Client*>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        if ((iter->second)->getNickname() == nickname)
            return (true);
    }
    return (false);    
}

/* remove */
void Server::removeClient(Client *client) {
    if (client) {
        int fd = client->getSocket();
        if (clients.find(fd) != clients.end()) {
            close(fd); // 클라이언트 소켓 닫기
            delete client; // 클라이언트 메모리 해제
            clients.erase(fd); // 맵에서 클라이언트 제거
        }
    }
}
