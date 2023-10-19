#include "../Server.hpp"

//PART #test
//   Command: PART
//Parameters: <channel>{,<channel>} [<reason>]
// PART명령은 지정된 채널에서 클라이언트를 제거합니다. 

//채널에 아무도 남지 않았다면 채널 삭제..?
void Server::part(MessageInfo *msg, Client *client)
{
    if (!msg->params.size())
        notEnoughParams(client->getSocket(), client->getNickname(), "");
    std::string channelName = msg->params[0];
    if (isExistChannel(channelName)) // 존재한다면
    {
        if ((channels[channelName]->isMember(client)) == false)
            MeNotOnChannel(client, channelName, client->getNickname());
        std::string sendMsg = "";
        sendMsg = "PART " + msg->params[0];
        sendMessageAll(client, sendMsg, msg->params[0]);
        removeClientFromChannel(msg->params[0], client); // 삭제
        client->setCurrentchannel("*");
    }
    else
        noSuchChannel(client->getSocket(), client->getNickname(), msg->params[0]);
}