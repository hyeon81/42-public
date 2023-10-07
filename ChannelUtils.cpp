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

void Server::setChannelMode(std::string channelName, ChannelMode mode, std::string param)
{
    //mode에 따라서 채널 모드 변경. 채널 모드에 따라 액션 실행 필요
    if (mode == INVITE)
    {
        //param에 해당하는 클라이언트를 초대
    }
    else if (mode == TOPIC)
    {
        //param에 해당하는 토픽으로 변경
    }
    else if (mode == KEY)
    {
        //param에 해당하는 키로 변경
    }
    else if (mode == OPER)
    {
        //param에 해당하는 클라이언트를 오퍼레이터로 변경
    }
    else if (mode == LIMIT)
    {
        //param에 해당하는 인원수로 변경
    }
    else
        throw std::runtime_error("no such mode");
    channels[channelName]->setMode(mode);
}

void Server::removeChannelMode(std::string channelName, ChannelMode mode, std::string param)
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

std::string Server::getChannelModes(std::string channelName)
{
    std::string res = "";
    int *modes = channels[channelName]->getModes();
    for (int i = 0; i < 5; i++)
    {
        if (modes[i] == 1)
        {
            if (i == 0)
                res.append("i");
            else if (i == 1)
                res.append("t");
            else if (i == 2)
                res.append("k");
            else if (i == 3)
                res.append("o");
            else if (i == 4)
                res.append("l");
        }
    }
    return (res);
}