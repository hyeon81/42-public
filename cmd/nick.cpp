#include "../Server.hpp"

//NICK root
//NICK
void Server::nick(MessageInfo &msg, Client *client)
{
    std::cout << "nick" << std::endl;
    //닉네임이 일치하는지 확인. params가 없으면?
    //닉네임이 있을경우 닉네임을 보여주고, 없으면 무시
    if (!msg.params.size())
        return;
    std::string nickname = msg.params[0];
    //중복되지 않는지 체크 필요
    //닉네임 정책에 맞는지도 체크 필요
    client->setNickname(nickname);
}