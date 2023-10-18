#include "../Server.hpp"

void Server::pass(MessageInfo *msg, Client *client) 
{
    std::string errorMsg;
    if (!msg->params.size())
    {
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
        removeClient(client);
        throw std::runtime_error("Not enough parameters"); //return 느낌...?

    }
    std::string clientPw = msg->params[0]; // 들어왔다면 첫번째 애를 저장
    if (clientPw == this->password)
        return ;
    else
    {
        errorMsg = ":ft_irc 464 :Password incorrect";
        sendResponse(errorMsg, client);
        removeClient(client);
        throw std::runtime_error("password incorrect");
    }
}



