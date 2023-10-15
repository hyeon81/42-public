#include "../Server.hpp"


void Server::pass(MessageInfo &msg, Client *client) 
{
    std::string errorMsg;
    if (!msg.params.size()) // pass가 안들어왔을 경우 그냥 리턴 ? or error
    {
        //ERR_NEEDMOREPARAMS (461) 
        //"<client> <command> :Not enough parameters"
        notEnoughParams(client->getSocket(), client->getNickname(), msg.cmd);
    }
    std::string clientPw = msg.params[0]; // 들어왔다면 첫번째 애를 저장
    if (clientPw == this->password) 
        client->setValid(true); // password의 유무를 판단하기 위해 만든거라 기능을 분리 할 필요가
    else
    {
        //ERR_PASSWDMISMATCH (464) 
        //"<client> :Password incorrect"
        errorMsg = ":ft_irc 464 " + client->getNickname() + " :Password incorrect";
        sendResponse(errorMsg, client);
        throw std::runtime_error("password incorrect");
    }
}

