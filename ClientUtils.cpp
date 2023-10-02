#include "Server.hpp"

void Server::addClient(Client &client)
{
    std::cout << "add client" << std::endl;
    if (client.getValid())
        this->clients.insert(std::make_pair(client.getSocket(), client));
}

Client &Server::getClientWithNickname(std::string nickname)
{
    std::cout << "Server getClientWithNickname" << std::endl;
    std::map<int, Client>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        if ((iter->second).getNickname() == nickname)
            return (iter->second);
    }
    //유저가 존재하지 않음
    throw std::runtime_error("no such user");
}
