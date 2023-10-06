#include "../Server.hpp"

//MODE
//권한 있는지 없는지 확인해야
void Server::mode(MessageInfo &msg, Client *client)
{
    if (!msg.params.size())
    {
        std::string msg = ":ft_irc 461 " + client->getNickname() + " :Not enough parameters";
        sendResponse(msg, client);
        throw std::runtime_error("no params");
    }
    //채널 모드 변경
    //맨처음 인자가 채널인지 확인
    std::string channelName = msg.params[0];
    if (!isExistChannel(channelName))
    {
        std::string msg = ":ft_irc 403 " + client->getNickname() + " " + channelName + " :Not enough parameters";
        sendResponse(msg, client);
        throw std::runtime_error("no channel");
        //유효한 채널 아님
    }
    //인자가 하나만 있을 경우 
    if (msg.params.size() == 1)
    {
        std::string msg = ":ft_irc 324 " + client->getNickname() + " " + channelName;
        //채널의 모드를 보여줌
    }
    //두번째 인자가 모드인지 확인
    //인자가 두개인데, 두번째 인자가 모드인지 확인
    if (msg.params[1].size() < 2)
    {
        //유효한 모드 인자 아님
    }
    
    //모드가 플러스인지 마이너스인지 확인
    char oper = msg.params[1][0];
    if (oper == '+' && oper == '-')
    {
        //유효한 모드인지 확인
        char modeChar = msg.params[1][1];
        if (modeChar == 'i' || modeChar == 't' || modeChar == 'k' || modeChar == 'o' || modeChar == 'l')
        {
            char modeOption[5] = {'i', 't', 'k', 'o', 'l'};
            int modeEnum[5] = {INVITE, TOPIC, KEY, OPER, LIMIT};

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
        else
        {
            //유효한 모드 인자 아님
        }
    } 
    else
    {
        //유효한 모드 인자 아님
    }
}