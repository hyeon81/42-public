#include "Channel.hpp"

Channel::Channel()
{
    std::cout << "Channel default constructor" << std::endl;
}

Channel::Channel(std::string name)
{
    std::cout << "Channel constructor" << std::endl;
    this->name = name;
    //모드 초기화
    memset(modes, 0, sizeof(modes));
}

Channel::~Channel()
{
    std::cout << "Channel destructor" << std::endl;
}

void Channel::addClient(Client *client)
{
    std::cout << "Channel addClient" << std::endl;
    this->clients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

void Channel::removeClient(Client *client)
{
    std::cout << "Channel removeClient" << std::endl;
    this->clients.erase(client->getSocket());
}

void Channel::setOperatorFd(Client *client)
{
    std::cout << "Channel setOperatorFd" << std::endl;
    oClients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

bool Channel::isOperator(int fd)
{
    std::cout << "Channel isOperator" << std::endl;
    if (oClients.find(fd) != oClients.end())
        return (true);
    return (false);
}

void Channel::showClients()
{
    std::cout << "Channel showClients" << std::endl;
    std::map<int, Client*>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        std::cout << (iter->second)->getNickname() << std::endl;
    }
}

std::vector<Client*> Channel::getChannelMembers(const std::string& channelName)
{
    std::vector<Client*> members;

    // if (name == channelName) 
    {
        for (std::map<int, Client*>::const_iterator it = clients.begin(); it != clients.end(); ++it) 
            members.push_back(it->second);
    }

    return members;
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

bool Channel::isModeApplied(ChannelMode mode)
{
    std::cout << "Channel isModeApplied" << std::endl;
    if (this->modes[mode] == 1)
        return (true);
    return (false);
}

void Channel::setMode(ChannelMode mode)
{
    std::cout << "Channel setMode: " << mode << std::endl;
    modes[mode] = 1;
}

void Channel::removeMode(ChannelMode mode)
{
    std::cout << "Channel removeMode: " << mode << std::endl;
    modes[mode] = 0;
}

int* Channel::getModes()
{
    std::cout << "Channel getModes" << std::endl;
    return (this->modes);
}

void Channel::addOperator(Client *client)
{
    std::cout << "Channel addOperator" << std::endl;
    this->oClients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

void Channel::addInvite(Client *client)
{
    std::cout << "Channel addInvite" << std::endl;
    this->iClients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

void Channel::setKey(std::string key)
{
    std::cout << "Channel setKey" << std::endl;
    this->key = key;
}

std::string Channel::getKey()
{
    return (this->key);
}


void Channel::removeOperator(Client *client)
{
    std::cout << "Channel removeOperator" << std::endl;
    this->oClients.erase(client->getSocket());
}

void Channel::removeInvite(Client *client)
{
    std::cout << "Channel removeInvite" << std::endl;
    this->iClients.erase(client->getSocket());
}

void Channel::removeKey()
{
    std::cout << "Channel removeKey" << std::endl;
    this->key = "";
}

void Channel::removeLimit()
{
    std::cout << "Channel removeLimit" << std::endl;
    this->limit = 0; //0으로 설정하는 게 맞나?
}

void Channel::setLimit(unsigned int limit)
{
    std::cout << "Channel setLimit" << std::endl;
    this->limit = limit;
}

int Channel::getLimit()
{
    return (this->limit);
}