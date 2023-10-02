#include "Server.hpp"

bool isExistChannel(std::string name)
{
    //존재한다면 true
    if (this->channels.find(name) != this->channels.end())
        return (true);
    return (false);
}

void addChannel(std::string name)
{

}

void removeChannel(std::string name)
{

}

void addClientToChannel(std::string name, Client &client)
{

}

void removeClientFromChannel(std::string name, Client &client)
{

}

void sendToChannel(std::string name, std::string msg)
{

}

