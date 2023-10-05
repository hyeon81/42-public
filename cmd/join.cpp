#include "../Server.hpp"

//JOIN #test
//추후에 쉼표도 처리
void Server::join(MessageInfo &msg, Client &client)
{
    std::cout << "join" << std::endl;
    //params가 있는지 확인
    if (!msg.params.size())
    {
        //인자가 없는 경우
        std::string msg = ":ft_irc 461 " + client.getNickname() + " JOIN :Not enough parameters";
        sendResponse(msg, client);
        throw std::runtime_error("no params");
    }

    std::string channelName = msg.params[0];
    //채널이 있는지 확인. 있는 채널이면 그 채널로, 없는 채널이면 새로 생성한다.
    if (isExistChannel(channelName))
    {
        //그냥 모드를 반환해야할듯 
        //INVITE, TOPIC, KEY, OPER, LIMIT
        if (isChannelModeApplied(channelName, LIMIT))
        {}
        //채널에 클라이언트 추가
        addClientToChannel(channelName, client);
    }
    else
    {
        //채널 생성
        addChannel(channelName);
        //채널에 클라이언트 추가
        addClientToChannel(channelName, client);
        //해당 클라이언트를 operator로 설정
        // setOperatorFd(client.getSocket());
    }
}
