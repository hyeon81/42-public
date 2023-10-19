#include "Channel.hpp"

Channel::Channel()
{
}

Channel::Channel(std::string name)
{
    this->name = name;
    memset(modes, 0, sizeof(modes));
}

Channel::~Channel()
{
}

void Channel::addClient(Client *client)
{
    this->clients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

void Channel::removeClient(Client *client)
{
    this->clients.erase(client->getSocket());
}

void Channel::setOperatorFd(Client *client)
{
    oClients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

bool Channel::isOperator(int fd)
{
    if (oClients.find(fd) != oClients.end())
        return (true);
    return (false);
}

void Channel::showClients()
{
    std::map<int, Client*>::iterator iter;
    for (iter = this->clients.begin(); iter != this->clients.end(); iter++)
    {
        std::cout << (iter->second)->getNickname() << std::endl;
    }
}

std::string &Channel::getTopic()
{
    return (this->topic);
}

void Channel::setTopic(std::string topic)
{
    this->topic = topic;
}

std::string &Channel::getName()
{
    return (this->name);
}

bool Channel::isModeApplied(ChannelMode mode)
{
    if (this->modes[mode] == 1)
        return (true);
    return (false);
}

void Channel::setMode(ChannelMode mode)
{
    modes[mode] = 1;
}

void Channel::removeMode(ChannelMode mode)
{
    modes[mode] = 0;
}

int* Channel::getModes()
{
    return (this->modes);
}

void Channel::addOperator(Client *client)
{
    this->oClients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

void Channel::addInvite(Client *client)
{
    this->iClients.insert(std::pair<int, Client*>(client->getSocket(), client));
}

void Channel::setKey(std::string key)
{
    this->key = key;
}

std::string Channel::getKey()
{
    return (this->key);
}


void Channel::removeOperator(Client *client)
{
    this->oClients.erase(client->getSocket());
}

void Channel::removeInvite(Client *client)
{
    this->iClients.erase(client->getSocket());
}

void Channel::removeKey()
{
    this->key = "";
}

void Channel::removeLimit()
{
    this->limit = 0;
}

void Channel::setLimit(unsigned int limit)
{
    this->limit = limit;
}

int Channel::getLimit()
{
    return (this->limit);
}

std::vector<Client*> Channel::getChannelMembers()
{
    std::vector<Client*> members;

    for (std::map<int, Client*>::const_iterator it = clients.begin(); it != clients.end(); it++)
        members.push_back(it->second);

    return members;
}

bool Channel::isMember(Client *client)
{
    if (clients.find(client->getSocket()) != clients.end())
    {
        return (true);
    }
    return (false);
}

bool Channel::isInvited(Client *client)
{
    if (iClients.find(client->getSocket()) != iClients.end())
        return (true);
    return (false);
}
