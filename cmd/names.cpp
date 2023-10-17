#include "../Server.hpp"

//NAMES #test
void Server::names(MessageInfo *msg, Client *client)
{
    //해당 채널의 사람들의 목록을 보여줌
    if (isExistChannel(msg->params[0]))
        channels[msg->params[0]]->showClients();
    //없는 채널이라면?
}
