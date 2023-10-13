#include "../Server.hpp"

//KICK
//채널에서 클라이언트를 강제로 제거합니다
//KICK &Melbourne Matthew
void Server::kick(MessageInfo &msg, Client *client)
{
    const channelName = msg.params[0];
    if (isExistChannel(channelName))
    {
        if (msg.params.size() > 2)
        {
            Client *user = getClient(msg.params[1]);
            //존재하지 않은 유저인지 확인
            if (!user)
            {
                noSuchNick(client->getSocket(), client->getNickname(), param);
                throw std::runtime_error("no such user");
            }
            //운영자인지 확인
            if (isOperatorClient(msg.params[0], client->getSocket()))
                removeClientFromChannel(msg.params[0], user);
            // else
            //     channelOperatorPrivilegesNeeded(client->getSocket(), client->getNickname(), channelName);
        }
    }
}
