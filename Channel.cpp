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