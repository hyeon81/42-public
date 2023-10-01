#include "Server.hpp"

void Server::addClient(Client &client)
{
    if (client.getValid())
        this->clients.insert(std::make_pair(client->getSocket(), client));
}