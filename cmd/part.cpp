#include "../Server.hpp"

//PART #test
//   Command: PART
//Parameters: <channel>{,<channel>} [<reason>]
// PART명령은 지정된 채널에서 클라이언트를 제거합니다. 

//채널에 아무도 남지 않았다면 채널 삭제..?
void Server::part(MessageInfo &msg, Client *client)
{
    if (!msg.params.size())
        notEnoughParams(client->getSocket(), client->getNickname(), "");
    if (isExistChannel(msg.params[0])) // 존재한다면
    {
        removeClientFromChannel(msg.params[0], client); // 삭제
        std::string sendMsg = "";
        if(msg.params[1].size())
        {
            sendMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + "PART " + msg.params[0] + " " + msg.params[1];
            sendMessageAll(client, sendMsg, msg.params[0]);
        }
        else
        {
            sendMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + "PART " + msg.params[0];
            sendMessageAll(client, sendMsg, msg.params[0]);
        }
    }
    else
        noSuchChannel(client->getSocket(), client->getNickname(), msg.params[0]);
}