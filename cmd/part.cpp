#include "../Server.hpp"

//PART #test
//   Command: PART
//Parameters: <channel>{,<channel>} [<reason>]
void Server::part(MessageInfo *msg, Client *client)
{
    if (!msg->params.size())
        notEnoughParams(client->getSocket(), client->getNickname(), "");
    std::string channelName = msg->params[0];
    if (isExistChannel(channelName)) // 존재한다면
    {
        if ((channels[channelName]->isMember(client)) == false)
            MeNotOnChannel(client, channelName);
        std::string sendMsg = "";
        sendMsg = "PART " + channelName;
        sendMessageAll(client, sendMsg, channelName);
        removeClientFromChannel(channelName, client); // 삭제
        client->setCurrentchannel("*");
    }
    else
        noSuchChannel(client->getSocket(), client->getNickname(), channelName);
}