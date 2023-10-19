#include "../Server.hpp"

/* 


127.000.000.001.06667-127.000.000.001.35666: 
:irc.local 311 root_ root root 127.0.0.1 * :root
:irc.local 312 root_ root irc.local :Local IRC Server
:irc.local 317 root_ root 160 1697529252 :seconds idle, signon time
:irc.local 318 root_ root :End of /WHOIS list.

127.000.000.001.06667-127.000.000.001.45120: 
:irc.local 311 root eko root 127.0.0.1 * :root
사용자 닉 , 누구에대한 정보인지 nick, 사용자 username, ip, *, 
 * :" + who->getRealName() + "\r\n


me->getNickname() + " " + nick + " " \
        + who->getUserName() +  " " + who->getIP() + " * :" + who->getRealName() + "\r\n";
:irc.local 312 root eko irc.local :Local IRC Server
:irc.local 317 root eko 7361 1697529362 :seconds idle, signon time
:irc.local 318 root eko :End of /WHOIS list.

:irc.local 311 _nick eko root 127.0.0.1 * :root
사용자의 nick, (상대방 nick, 상대방 username),ip,   상대방 네임

:irc.local 312 _nick eko irc.local :Local IRC Server
:irc.local 317 _nick eko 7607 1697529362 :seconds idle, signon time
:irc.local 318 _nick eko :End of /WHOIS list.
*/

// bool Channel::isOperator(int fd)
// {
//     std::cout << "Channel isOperator" << std::endl;
//     if (oClients.find(fd) != oClients.end())
//         return (true);
//     return (false);
// }

// :irc.local 311 root root root 127.0.0.1 * :root
// :irc.local 378 root root :is connecting from root@127.0.0.1 127.0.0.1
// :irc.local 319 root root :@#hello
// :irc.local 312 root root irc.local :Local IRC Server
// :irc.local 379 root root :is using modes +i
// :irc.local 317 root root 65 1697620974 :seconds idle, signon time
// :irc.local 318 root root :End of /WHOIS list.

// :irc.local 311 root root root 127.0.0.1 * :root
// :irc.local 378 root root :is connecting from root@127.0.0.1 127.0.0.1
// :irc.local 319 root root :@#hello
// :irc.local 312 root root irc.local :Local IRC Server
// :irc.local 379 root root :is using modes +i
// :irc.local 317 root root 231 1697620974 :seconds idle, signon time
// :irc.local 318 root root :End of /WHOIS list.

void Server::whois(MessageInfo *msg, Client *client)
{
    Client *targetClient = getClient(msg->params[0]);

    if(targetClient)
    {
        std::cout << "targetClient 널 아닌데유" << std::endl;
        /*311*/
        std::string msg311 = "ft_irc 311 " + client->getNickname() + " " + targetClient->getNickname() + 
            targetClient->getUsername() + "127.0.0.1 * :" + targetClient->getRealname() + "\r\n";
        /*312*/
        std::string msg312 = "ft_irc 312 " + client->getNickname() + " " + targetClient->getNickname() + 
            "ft_irc :Local IRC Server" + "\r\n";
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
            std::string msg319 = "ft_irc 312 " + client->getNickname() + " " + targetClient->getNickname() + " :@" +targetClient->getCurrentchannel() + "\r\n";
            sendResponse(msg311 + msg319 + msg312 + msg317 + msg318, client);

        }
        else
            sendResponse(msg311 + msg312 + msg317 + msg318, client);
    }
    else
    {
        std::cout << "targetClient 널 인데유" << std::endl;
        
        noSuchNick(client->getSocket(), msg->params[0], msg->cmd);
    }
}
