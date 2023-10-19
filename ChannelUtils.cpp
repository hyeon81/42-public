#include "Server.hpp"

bool Server::isExistChannel(std::string name)
{
    if (this->channels.find(name) != this->channels.end())
        return (true);
    return (false);
}

void Server::addChannel(std::string name)
{
    if (isExistChannel(name))
        return;
    channels.insert(std::make_pair(name, new Channel(name)));
}

void Server::removeChannel(std::string name)
{
    if (!isExistChannel(name))
        return ;
    delete channels[name];
    channels.erase(name);
}

void Server::addClientToChannel(std::string name, Client *client, std::string password)
{
    //key확인
    if (channels[name]->isModeApplied(KEY))
    {
        //:irc.local 475 root_ #hello :Cannot join channel (incorrect channel key)
        if (channels[name]->getKey() != password)
            badChannelKey(client, name);
    }

    //invite된 사람인지 확인
    //:irc.local 473 root_ #hello :Cannot join channel (invite only)
    if (channels[name]->isModeApplied(INVITE))
    {
        if (!(channels[name]->isInvited(client)))
            inviteOnly(client, name);
    }

    //limit모드인지 확인
    if (channels[name]->isModeApplied(LIMIT))
    {
        if (channels[name]->getLimit() != 0 && (channels[name]->getLimit() <= (int)(channels[name]->getChannelMembers().size())))
            channelIsFull(client, name);
    }
    
    channels[name]->addClient(client);
}

void Server::removeClientFromChannel(std::string name, Client *client)
{
    //:root!root@127.0.0.1 KICK #hello root :sdjfjklsdflfds
    //해당 유저 채널에서 제거
    if (!channels[name]->isMember(client))
        return ;
    channels[name]->removeClient(client);
    channels[name]->removeOperator(client);
    channels[name]->removeInvite(client);
    //채널에 아무도 없으면 채널 삭제
    if (channels[name]->getChannelMembers().size() == 0)
        removeChannel(name);
}

bool Server::isOperatorClient(std::string channelName, int fd)
{
    if (channels.find(channelName) != channels.end())
    {
        return channels[channelName]->isOperator(fd);
    }
    return (false);
}

bool Server::isChannelModeApplied(std::string channelName, ChannelMode mode)
{
    return (channels[channelName]->isModeApplied(mode));
}

Channel *Server::getChannel(std::string channelName)
{
    return (channels[channelName]);
}

std::string Server::getChannelModes(std::string channelName)
{
    std::string res = "+";
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

void Server::addChannelOperator(std::string channelName, std::string nickname)
{
    channels[channelName]->addOperator(getClient(nickname));
}

void Server::addChannelInvite(std::string channelName, std::string nickname)
{
    channels[channelName]->addInvite(getClient(nickname));
}
