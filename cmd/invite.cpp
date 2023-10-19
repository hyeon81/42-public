#include "../Server.hpp"

//INVITE root #test
//:Angel INVITE Wiz #Dust??
void Server::invite(MessageInfo *msg, Client *client)
{
    if (msg->params.size() < 2)
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
    const std::string channelName = msg->params[1];
    if (isExistChannel(channelName))
    {
        if (msg->params.size() > 1)
        {
            if ((channels[channelName]->isMember(client)) == false)
                MeNotOnChannel(client, channelName);
            Client *user = getClient(msg->params[0]);
            if (!user)
                noSuchNick(client->getSocket(), client->getNickname(), msg->params[0]);
            if (channels[channelName]->isMember(user))
            {
                std::string sendMsg = ":ft_irc 443 " + client->getNickname() + " " + user->getNickname() + " " + channelName + " :is already on channel";
                sendResponse(sendMsg, client);
                return ;
            }
            addChannelInvite(channelName, user->getNickname());
            //:irc.local 341 root_ root__ :#hi
            std::string invite_msg = ":ft_irc 341 " + client->getNickname() + " " + user->getNickname() + " :" + channelName;
            sendResponse(invite_msg, user);
            //:root_!root@127.0.0.1 INVITE root__ :#hi
            std::string allMsg = "INVITE " + user->getNickname() + " :" + channelName;
            sendMessageAll(client, allMsg, channelName);
        }
    }
    else
        noSuchChannel(client->getSocket(), client->getNickname(), channelName);
}
