#include "Server.hpp"

bool Server::isExistChannel(std::string name)
{
    //존재한다면 true
    if (this->channels.find(name) != this->channels.end())
        return (true);
    return (false);
}

void Server::addChannel(std::string name)
{
    channels.insert(std::make_pair(name, new Channel(name)));
}

void Server::removeChannel(std::string name)
{
    channels.erase(name);
}

void Server::addClientToChannel(std::string name, Client *client)
{
    channels[name]->addClient(client);
}

void Server::removeClientFromChannel(std::string name, Client *client)
{
    channels[name]->removeClient(client);
}

void Server::sendToChannel(std::string name, std::string msg)
{

}

bool Server::isOperatorClient(std::string channelName, int fd)
{
    return (channels[channelName]->isOperator(fd));
}

void Server::setChannelMode(std::string channelName, int mode)
{
    //mode에 따라서 채널 모드 변경. 채널 모드에 따라 액션 실행 필요
    channels[channelName]->setMode(mode);
}

void Server::removeChannelMode(std::string channelName, int mode)
{
    //mode에 따라서 채널 모드 변경. 채널 모드에 따라 액션 실행 필요
    channels[channelName]->removeMode(mode);
}

bool Server::isChannelModeApplied(std::string channelName, ChannelMode mode)
{
    return (channels[channelName]->isModeApplied(mode));
}

Channel *Server::getChannel(std::string channelName)
{
    return (channels[channelName]);
    throw std::runtime_error("no channel");
}