#include "../Server.hpp"

bool checkModeArgu(std::string &argu)
{
    //모드가 플러스인지 마이너스인지 확인
    if (argu.size() < 2)
        return (false);
    char oper = argu[0];
    if (oper != '+' && oper != '-')
        return (false);
    //유효한 모드인지 확인
    char modeChar = mode[1];
    if (modeChar != 'i' && modeChar != 't' && modeChar != 'k' && modeChar != 'o' && modeChar != 'l')
        return (false)
    return (true);
}

//MODE 채널명 모드명 [모드매개변수]
//권한 있는지 없는지 확인해야
void Server::mode(MessageInfo &msg, Client *client)
{
    if (!msg.params.size())
    {
        std::string msg = ":ft_irc 461 " + client->getNickname() + " :Not enough parameters";
        sendResponse(msg, client);
        return ;
    }
    //채널 모드 변경
    //맨처음 인자가 채널인지 확인
    std::string channelName = msg.params[0];
    if (!isExistChannel(channelName))
    {
        std::string msg = ":ft_irc 403 " + client->getNickname() + " " + channelName + " :Not enough parameters";
        sendResponse(msg, client);
        return ;
        //유효한 채널 아님
    }
    //인자가 하나만 있을 경우. 즉 채널명만 있을 경우
    if (msg.params.size() == 1)
    {
        std::string msg = ":ft_irc 324 " + client->getNickname() + " " + getChannelModes(channelName);
        sendResponse(msg, client);
        return ;
    }
    //인자가 두개인데, 두번째 인자가 모드인지 확인
    if (!checkModeArgu(msg.params[1]))
    {
        //유효한 모드 인자 아님
        std::string msg = ":ft_irc 403 " + client->getNickname() + " " + msg.params[1] + " :is unknown mode char to me";
        sendResponse(msg, client);
        return ;
    }
    
    std::string modeArgu;
    if (msg.params.size() == 3)
        modeArgu = msg.params[2];

    char modeChar = msg.params[1][1];
    char modeOption[5] = {'i', 't', 'k', 'o', 'l'};
    ChannelMode modeEnum[5] = {INVITE, TOPIC, KEY, OPER, LIMIT};
    for (int i = 0; i < 5; i++)
    {
        if (modeChar == modeOption[i])
        {
            //모드 적용
            if (oper == '+')
                setChannelMode(channelName, modeEnum[i]);
            else if (oper == '-')
                removeChannelMode(channelName, modeEnum[i]);
        }
    }
}