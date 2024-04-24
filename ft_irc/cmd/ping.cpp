#include "../Server.hpp"

//연결의 다른 쪽이 여전히 연결되어 있는지 확인하거나 애플리케이션 계층에서 연결 대기 시간을 확인하기 위해 클라이언트 또는 서버에서 전송
void Server::ping(MessageInfo *msg, Client *client) 
{
    //:irc.local PONG irc.local :irc.local\r\n
    if (msg)
    {
        std::string sendMsg = ":ft_irc PONG ft_irc :ft_irc";
        sendResponse(sendMsg, client);
    }
}
