#include "../Server.hpp"

//채널에서 클라이언트를 강제로 제거합니다
//KICK &Melbourne Matthew
void Server::kick(MessageInfo *msg, Client *client)
{
    if (!msg->params.size())
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
    std::string channelName = msg->params[0];
    if (isExistChannel(channelName))
    {
        if (msg->params.size() > 1)
        {
            //내가 채널에 있는지 확인
            if ((channels[channelName]->isMember(client)) == false)
                MeNotOnChannel(client, channelName);
            Client *user = getClient(msg->params[1]);
            //존재하지 않은 유저인지 확인
            if (user == NULL)
                noSuchNick(client->getSocket(), client->getNickname(), msg->params[1]);
            //존재 하지만 채널에 없는 유저인지 확인
            if (!channels[channelName]->isMember(user))
                notOnChannel(client, channelName, msg->params[1]);
            //운영자인지 확인
            if (isOperatorClient(msg->params[0], client->getSocket()))
            {
                //:root!root@127.0.0.1 KICK #hello root_ :
                std::string msgs = "KICK " + channelName + " " + user->getNickname() + " :";
                sendMessageAll(client, msgs, channelName);
                user->setCurrentchannel("*");
                removeClientFromChannel(msg->params[0], user);
            }
            else
                noChannelOperPrivileges(client->getSocket(), client->getNickname(), channelName);
        }
    } 
    else
        noSuchChannel(client->getSocket(), client->getNickname(), channelName);
}