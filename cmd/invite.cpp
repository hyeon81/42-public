#include "../Server.hpp"

//INVITE
//INVITE root #test
//:Angel INVITE Wiz #Dust??
//채널에 닉네임 초대
void Server::invite(MessageInfo &msg, Client *client)
{
    //+i 모드일경우 초대보내는 클라이언트가 해당 채널의 채널 운영자로 인식되어야
    //매개변수 없을 경우
    if (!msg.params.size())
        return;
    //다른 유저 초대
    if (isExistChannel(msg.params[0]))
    {
        //채널에 클라이언트 추가. 유저의 닉네임으로 fd 찾는 함수 만들어야
        if (msg.params.size() > 2)
        {
            Client *user = getClient(msg.params[1]);
            addClientToChannel(msg.params[0], user);
        }
    }
}
