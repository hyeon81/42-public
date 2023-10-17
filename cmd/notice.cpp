#include "../Server.hpp"

// <nickname> <text>
void Server::notice(MessageInfo *msg, Client *client) // 정확히 뭔 기능이지.. 감이 안온다...?
{
    if (msg->params.size() < 2) 
    {
        std::string msg = "<client> <command> :Not enough parameters";
        sendResponse(msg, client);
    }
    std::string target = msg->params[0];
    std::string message = msg->params[1];
        // 대상 클라이언트가 존재하지 않는 경우 에러 -> ERR_NOSUCHNICK(401)
}