#include "Channel.hpp"

Channel::Channel()
{
    std::cout << "Channel default constructor" << std::endl;
}

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

bool Channel::isOperator(int fd)
{
    std::cout << "Channel isOperator" << std::endl;
    if (this->operatorFd == fd)
        return (true);
    return (false);
}

void Channel::showClients()
{
    std::cout << "Channel showClients" << std::endl;
    std::map<int, Client>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        std::cout << (iter->second).getNickname() << std::endl;
    }
}

std::string &Channel::getTopic()
{
    std::cout << "Channel getTopic" << std::endl;
    return (this->topic);
}

void Channel::setTopic(std::string topic)
{
    std::cout << "Channel setTopic" << std::endl;
    this->topic = topic;
}

std::string &Channel::getName()
{
    std::cout << "Channel getName" << std::endl;
    return (this->name);
}

std::string &Channel::getMode()
{
    std::cout << "Channel getMode" << std::endl;
    return (this->mode);
}

void Channel::setMode(std::string mode)
{
    std::cout << "Channel setMode" << std::endl;
    this->mode = mode;
}

