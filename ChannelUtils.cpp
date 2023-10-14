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
        if (!channels[name]->isInvited(client))
        {
            inviteOnly(client, name);
            throw std::runtime_error("invite only");
        }
    }

    //limit모드인지 확인
    if (channels[name]->isModeApplied(LIMIT))
    {
        if (channels[name]->getLimit() <= channels[name]->getClients().size())
            channelIsFull(client, name);
    }
    
    channels[name]->addClient(client);
}

void Server::removeClientFromChannel(std::string name, Client *client)
{
    //모든 클라이언트에게 알림
    //:root!root@127.0.0.1 KICK #hello root :sdjfjklsdflfds
    channels[name]->removeClient(client);
    //밴 목록에 추가
}

void Server::sendToChannel(std::string name, std::string msg)
{
    std::vector<Client*> members = channels[channelName]->getChannelMembers();
    for (size_t i = 0; i < members.size(); i++) {
        sendResponse(userList, members[i]);
    }
}

bool Server::isOperatorClient(std::string channelName, int fd)
{
    return (channels[channelName]->isOperator(fd));
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

void Server::addChannelOperator(std::string channelName, std::string nickname)
{
    channels[channelName]->addOperator(getClient(nickname));
}

void Server::addChannelInvite(std::string channelName, std::string nickname)
{
    channels[channelName]->addInvite(getClient(nickname));
}
