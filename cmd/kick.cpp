#include "../Server.hpp"

//KICK
//채널에서 클라이언트를 강제로 제거합니다
//KICK &Melbourne Matthew
void Server::kick(MessageInfo &msg, Client *client)
{
    if (isExistChannel(msg.params[0]))
    {
        if (msg.params.size() > 2)
        {
            Client *user = getClient(msg.params[1]);
            //운영자인지 확인
            if (isOperatorClient(msg.params[0], client->getSocket()))
                removeClientFromChannel(msg.params[0], user);
        }
    }
}
