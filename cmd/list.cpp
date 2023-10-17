#include "../Server.hpp"

//LIST
//LIST #twilight_zone,#42
//서버의 모든 채널 나열
/* 매개변수 있으면 해당 채널의 상태만 표시? */
void Server::list(MessageInfo *msg, Client *client)
{
    std::cout << "list" << std::endl;
    std::map<std::string, Channel*>::iterator iter;
    for (iter = channels.begin(); iter != channels.end(); iter++)
    {
        std::cout << (iter->second)->getName() << std::endl;
    }
}