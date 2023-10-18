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

    // "<client> <server name> :No such server"

    //인자가 덜 들어왔을때 처
    //username, realname이 겹칠 경우 조치 필요
    client->setUsername(username, realname);
    // //유저가 들어왔을때 client 등록한다고 판단. pass와 nick이 먼저 들어와야함.
    // client->setValid(true); 
    addClientToServer(client);
    client->showInfo();
    //RPL_WELCOME (001) 
    //"<client> :Welcome to the <networkname> Network, <nick>[!<user>@<host>]"
    //:irc.local 001 root :Welcome to the Localnet IRC Network root!root@127.0.0.1
    //:ft_irc 001 hello :Welcome to the Localnet IRC Network hello!hyeokim2@127.0.0.1
    //  "<client> :Welcome to the <networkname> Network, <nick>[!<user>@<host>]"
    std::string sendMsg = ":ft_irc 001 " + client->getNickname() + " :Welcome to the Localnet " + "ft_irc Network " + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1";
    sendResponse(sendMsg, client);

    // std::string endMsg = ":ft_irc 376 " + client->getNickname() + " :End of MOTD command";
    // sendResponse(endMsg, client);
}




