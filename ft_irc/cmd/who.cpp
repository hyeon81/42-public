#include "../Server.hpp"

void Server::who(MessageInfo *msg, Client *client)
{

    std::string sendMsg = "";
    std::string isO = "";

    if(msg->params[0][0] == '#') //channel
    {
        if(isExistChannel(msg->params[0]))
        {
            std::vector<Client*> members = getChannel(msg->params[0])->getChannelMembers();
            for (size_t i = 0; i < members.size(); i++)
            {
                if(isOperatorClient(members[i]->getCurrentchannel(), members[i]->getSocket()))
                    isO = "H@";
                else
                    isO = "H";
                sendMsg = ":ft_irc 352 " + client->getNickname() + " " + msg->params[0] + " " +
                client->getUsername() + "127.0.0.1 " + "ft_irc" + members[i]->getNickname() + isO + " :0" + members[i]->getUsername();
                sendResponse(sendMsg, client);
            }
            sendMsg = ":ft_irc 315 " + client->getNickname() + " " + msg->params[0] + " :End of /WHO list.";
            sendResponse(sendMsg, client);
        }
        else
            noSuchChannel(client->getSocket(), client->getNickname(), msg->cmd);
    }
    else //client
    {
        Client *targetClient = getClient(msg->params[0]);
        if(targetClient)
        {
            if(isOperatorClient(targetClient->getCurrentchannel(), targetClient->getSocket()))
                isO = "H@";
            else
                isO = "H";
            sendMsg = ":ft_irc 352 " + client->getNickname() + " " + targetClient->getCurrentchannel() + " " +
                client->getUsername() + "127.0.0.1 " + "ft_irc" + targetClient->getNickname() + isO + " :0" + targetClient->getUsername();
            sendMsg = ":ft_irc 315 " + client->getNickname() + " " + client->getNickname() + " :End of /WHO list.";
            
            sendResponse(sendMsg, client);
        }
        else
            noSuchNick(client->getSocket(), client->getNickname(), msg->cmd);
    }
}
