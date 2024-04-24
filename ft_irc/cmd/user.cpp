#include "../Server.hpp"

//USER root root 127.0.0.1 :root
//<username> <hostname> <servername> <realname> 
void Server::user(MessageInfo *msg, Client *client)
{
    if (clients.find(client->getSocket()) != clients.end())
    {
         std::string msg = ":ft_irc 462 " + client->getNickname() + " USER :Unauthorized command (already registered)";
         sendResponse(msg, client);
         return;
    }
    //유저일때는 parmas 없어도 응답 보냄.
    if (msg->params.size() < 4)
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
    //hostname
    std::string username = msg->params[0];
    std::string ip = msg->params[1]; // 127.0.0.1
    std::string servername = msg->params[2]; // www.google.com
    std::string realname = msg->params[3];

    client->setUsername(username, realname);
    addClientToServer(client);
    
    //:ft_irc 001 hello :Welcome to the Localnet IRC Network hello!hyeokim2@127.0.0.1
    std::string sendMsg = ":ft_irc 001 " + client->getNickname() + " :Welcome to the Localnet " + "ft_irc Network " + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1";
    sendResponse(sendMsg, client);
}




