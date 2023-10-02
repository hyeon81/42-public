#include "Channel.hpp"

Channel::Channel(std::string name)
{
    std::cout << "Channel constructor" << std::endl;
    this->name = name;
}

Channel::~Channel()
{
    std::cout << "Channel destructor" << std::endl;
}

void Channel::addClient(Client &client)
{
    std::cout << "Channel addClient" << std::endl;
    this->clients.insert(std::pair<int, Client>(client.getSocket(), client));
}

void Channel::removeClient(Client &client)
{
    std::cout << "Channel removeClient" << std::endl;
    this->clients.erase(client.getSocket());
}

void Channel::setOperatorFd(int fd)
{
    std::cout << "Channel setOperatorFd" << std::endl;
    this->operatorFd = fd;
}

bool isOperator(int fd)
{
    std::cout << "Channel isOperator" << std::endl;
    if (this->operatorFd == fd)
        return (true);
    return (false);
}
