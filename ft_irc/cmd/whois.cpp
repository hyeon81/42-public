#include "../Server.hpp"

/* 
127.000.000.001.06667-127.000.000.001.35666: 
:irc.local 311 root_ root root 127.0.0.1 * :root
:irc.local 312 root_ root irc.local :Local IRC Server
:irc.local 317 root_ root 160 1697529252 :seconds idle, signon time
:irc.local 318 root_ root :End of /WHOIS list.
*/

void Server::whois(MessageInfo *msg, Client *client)
{
    Client *targetClient = getClient(msg->params[0]);

    if(targetClient)
    {
        /*311*/
        std::string msg311 = "ft_irc 311 " + client->getNickname() + " " + targetClient->getNickname() + " " +
            targetClient->getUsername() + " 127.0.0.1 * :" + targetClient->getRealname() + "\r\n";
        /*312*/
        std::string msg312 = "ft_irc 312 " + client->getNickname() + " " + targetClient->getNickname() + 
            " ft_irc :Local IRC Server" + "\r\n";
        /*317*/
        targetClient->updateIdleTime();
        std::string msg317 = ":ft_irc 317 " + client->getNickname() + " " + targetClient->getNickname() +
        " " + std::to_string(targetClient->getIdleTime()) + " " + std::to_string(targetClient->getSignonTime()) +
        " :seconds idle, signon time" + "\r\n";
        /*318*/
        std::string msg318 = ":ft_irc 318 " + client->getNickname() + " " + targetClient->getNickname() +
        ":End of/WHOIS list.";
        if(isOperatorClient(targetClient->getCurrentchannel(), targetClient->getSocket()))
        {
            std::string msg319 = "ft_irc 319 " + client->getNickname() + " " + targetClient->getNickname() + " :@" +targetClient->getCurrentchannel() + "\r\n";
            sendResponse(msg311 + msg319 + msg312 + msg317 + msg318, client);

        }
        else
            sendResponse(msg311 + msg312 + msg317 + msg318, client);
    }
    else
    {
        noSuchNick(client->getSocket(), msg->params[0], msg->cmd);
    }
}
