#include "Server.hpp"

void Server::addClientToServer(Client *client)
{
    if (client->getValid())
        this->clients.insert(std::make_pair(client->getSocket(), client));
}

Client *Server::getClient(std::string nickname)
{
    std::map<int, Client*>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        if ((iter->second)->getNickname() == nickname)
            return (iter->second);
    }
    return (NULL);
}

bool Server::isExistClient(std::string nickname)
{
    std::map<int, Client*>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        if ((iter->second)->getNickname() == nickname)
            return (true);
    }
    return (false);    
}

void Server::removeClient(Client *client) {
    if (client) {
        if (client->getCurrentchannel() != "*")
            removeClientFromChannel(client->getCurrentchannel(), client);
        int fd = client->getSocket();
        if (clients.find(fd) != clients.end()) {
            clients.erase(fd); // 맵에서 클라이언트 제거
            nClients.erase(fd);
            close(fd); // 클라이언트 소켓 닫기
            delete client; // 클라이언트 메모리 해제
        }
    }
}
