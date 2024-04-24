#include "../Server.hpp"

//Command: PRIVMSG
//Parameters: <target>{,<target>} <text to be sent>
void Server::privmsg(MessageInfo *msg, Client *client)
{
    if(!msg->params.size())
        notEnoughParams(client->getSocket(), client->getNickname(), "");
    if(msg->params[0][0] == '#')
    {
        //:root__!root@127.0.0.1 PRIVMSG #hi :hihhih
        if(isExistChannel(msg->params[0]))
        {
            std::string resMsg = "";
            resMsg += msg->cmd + " ";
            for (unsigned long i = 0; i < msg->params.size(); i++)
            {
                resMsg += msg->params[i];
                if (i != msg->params.size() - 1)
                    resMsg += " ";
            }
            sendMessageAllWithOutMe(client, resMsg, msg->params[0]);
        }
        else
            noSuchChannel(client->getSocket(), client->getNickname(), msg->params[0]);
    }
    else 
    {
        Client *targetClient = getClient(msg->params[0]);
        if(targetClient)
        {
            std::string sendMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + "PRIVMSG " + msg->params[1];
            sendResponse(sendMsg, client);
        }
        else
            noSuchNick(client->getSocket(), client->getNickname(), msg->params[0]);
    }
    ;
}
