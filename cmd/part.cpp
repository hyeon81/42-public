#include "../Server.hpp"

//PART #test
/* 채널의 경우 쉼표(,)가 들어오는 경우 체크하기*/
void Server::part(MessageInfo &msg, Client &client)
{
    if (!msg.params.size())
        return;
    if (isExistChannel(msg.params[0]))
    {
        //채널에 클라이언트 제거
        removeClientFromChannel(msg.params[0], client);
        // if (isOperator(client.getSocket()))
        // {
        //     //다른 클라이언트를 operator로 설정?
        //     //얘가 마지막 클라이언트면 채널 제거?
        // }
    }
}