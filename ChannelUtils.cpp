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

// Command: MODE
// Parameters: <target> [<modestring> [<mode arguments>...]]
//내 생각엔 앞의 + -를 가져와서 같이 처리해야 할듯.
void Server::setChannelMode(std::string channelName, ChannelMode mode, std::string nickname)
{
    channelName *channel = channels[channelName];
    //mode에 따라서 채널 모드 변경. 채널 모드에 따라 액션 실행 필요
    //이미 채널에 있는 상태여야 함.
    if (mode == INVITE)
    {
        //param에 해당하는 클라이언트를 초대
        //MODE hello +i dkd
        if (nickname)
        {
            Client *user = getClient(nickname); //없는 유저면 throw 되려나?
            if (!user)
            {
                sendResponse("no such user", client);
                throw std::runtime_error("no such user");
            }
            //inviteClient
            channel->addClient(user);
            //params가 존재하는 유저인지 확인
        }
        //없으면? 
        else
        {
            
        }    
        //실패시 그냥 리턴
    }
    //Set/remove the restrictions of the TOPIC command to channel operators (TOPIC 명령어의 제한 두는 것을set/remove)
    else if (mode == TOPIC) 
    {
        //1. 채널 이름이 맞는지 확인
        //2. 채널 이름이 맞다면? operator 전용으로 변경 (mode의 topic이 1이라는건? topic을 operator만 제한한다는 걸로 받아들이기. 고로 여기서 설정해줄건x)
    }
    else if (mode == KEY)
    {
        //1. 채널 이름이 맞는지 확인
        //2. param에 해당하는 키로 변경
    }
    else if (mode == OPER)
    {
        //1. 채널 이름이 맞는지 확인
        //2. param에 해당하는 클라이언트를 오퍼레이터로 변경 (op_client에 포함시키기)
        ///MODE #irssi +o mike
        //param에 해당하는 클라이언트를 오퍼레이터로 변경
    }
    else if (mode == LIMIT)
    {
        //param에 해당하는 인원수로 변경
    }
    else
        throw std::runtime_error("no such mode");
    channel->setMode(mode);
}

void Server::removeChannelMode(std::string channelName, ChannelMode mode, std::string nickname)
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