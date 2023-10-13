#include "../Server.hpp"

//USER root root 127.0.0.1 :root
//<username> <hostname> <servername> <realname> 
void Server::user(MessageInfo &msg, Client *client)
{
    //유저일때는 parmas 없어도 응답 보냄.
    if (msg.params.size() < 4)
    {
        std::string errorMsg = "<client> <command> :Not enough parameters";
        sendResponse(errorMsg, client);
    }
    //hostname
    std::string username = msg.params[0];
    std::string ip = msg.params[1]; // 127.0.0.1
    std::string servername = msg.params[2]; // www.google.com
    std::string realname = msg.params[3];

    // "<client> <server name> :No such server"

    //인자가 덜 들어왔을때 처
    //username, realname이 겹칠 경우 조치 필요
    client->setUsername(username, realname);
    client->setIp(ip);
    // //유저가 들어왔을때 client 등록한다고 판단. pass와 nick이 먼저 들어와야함.
    // client->setValid(true); 
    addClient(client);
    sendResponse("<client> Welcome to the <networkname> Network, <nick>[!<user>@<host>]", client);
}




