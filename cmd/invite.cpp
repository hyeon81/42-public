#include "../Server.hpp"

//INVITE
//INVITE root #test
//:Angel INVITE Wiz #Dust??
//채널에 닉네임 초대
void Server::invite(MessageInfo *msg, Client *client)
{
    //+i 모드일경우 초대보내는 클라이언트가 해당 채널의 채널 운영자로 인식되어야
    //매개변수 없을 경우 (그럴 일은 없을듯)
    if (msg->params.size() < 2)
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
    //다른 유저 초대
    const std::string channelName = msg->params[1];
    if (isExistChannel(channelName))
    {
        //채널에 클라이언트 추가. 유저의 닉네임으로 fd 찾는 함수 만들어야
        if (msg->params.size() > 1)
        {
            Client *user = getClient(msg->params[0]);
            if (!user)
                noSuchNick(client->getSocket(), client->getNickname(), msg->params[0]);
            addChannelInvite(channelName, user->getNickname());
            //초대받은 유저에게 보내기
            //:irc.local 341 root_ root__ :#hi
            std::string invite_msg = ":ft_irc 341 " + user->getNickname() + " " + client->getNickname() + " :" + channelName;
            sendResponse(invite_msg, user);
            //모든 사람에게 보내기
            //:root_!root@127.0.0.1 INVITE root__ :#hi
            std::string allMsg = "INVITE " + user->getNickname() + " :" + channelName;
            sendMessageAll(client, allMsg, channelName);
        }
    }
    else
        noSuchChannel(client->getSocket(), client->getNickname(), channelName);
}
