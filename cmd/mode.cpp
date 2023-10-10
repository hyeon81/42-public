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
//MODE 모드명도 가능한듯 - 이건 나중에 확인
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
                setChannelMode(channelName, modeEnum[i], modeArgu);
            else if (oper == '-')
                removeChannelMode(channelName, modeEnum[i], modeArgu);
        }
    }
}


// Command: MODE
// Parameters: <target> [<modestring> [<mode arguments>...]]
//내 생각엔 앞의 + -를 가져와서 같이 처리해야 할듯.
//근데 operator가 있어야 mode도 가능한가?
//channelName = param[0], param = params[2]
void Server::setChannelMode(std::string channelName, ChannelMode mode, std::string param)
{
    channelName *channel = channels[channelName];
    //mode에 따라서 채널 모드 변경. 채널 모드에 따라 액션 실행 필요
    //이미 채널에 있는 상태여야 함.
    if (mode == INVITE)
    {
        //param에 해당하는 클라이언트를 초대
        //MODE hello +i dkd
        if (param)
        {
            Client *user = getClient(param); //없는 유저면 throw 되려나?
            if (!user)
            {
                noSuchNick(client->getSocket(), client->getNickname(), param);
                throw std::runtime_error("no such user");
            }
            //inviteClient
            channel.addChannelInvite(param);
            //이후 클라이언트에게 invite 메시지 전송
            invitingRPL(user->getSocket(), param, channelName);
        }
        //없으면? 
        else
            notEnoughParams(client->getSocket(), client->getNickname(), "MODE");
        //실패시 그냥 리턴
    }
    //Set/remove the restrictions of the TOPIC command to channel operators (TOPIC 명령어의 제한 두는 것을set/remove)
    else if (mode == TOPIC) 
    {
        //1. 채널 이름이 맞는지 확인
        //2. 채널 이름이 맞다면? operator 전용으로 변경 (mode의 topic이 1이라는건? topic을 operator만 제한한다는 걸로 받아들이기. 고로 여기서 설정해줄건x)
    }
    else if (mode == KEY)
    {
        //1. 채널 이름이 맞는지 확인
        //2. param에 해당하는 키로 변경
        //키가 규칙에 맞는지 체크
        if (param)
            setKey(param);
        else
            notEnoughParams(client->getSocket(), client->getNickname(), "MODE"); //수정 필요
    }
    else if (mode == OPER)
    {
        //1. 채널 이름이 맞는지 확인
        //2. param에 해당하는 클라이언트를 오퍼레이터로 변경 (op_client에 포함시키기)
        ///MODE #irssi +o mike
        //param에 해당하는 클라이언트를 오퍼레이터로 변경
        if (param)
        {
            Client *user = getClient(param); //없는 유저면 throw 되려나?
            if (!user)
            {
                noSuchNick(client->getSocket(), client->getNickname(), param);
                throw std::runtime_error("no such user");
            }
            //inviteClient
            channel.addChannelOperator(param);
            //이후 클라이언트에게 operator 메시지 전송
            // invitingRPL(user->getSocket(), param, channelName);
        }

    }
    else if (mode == LIMIT)
    {
        //param에 해당하는 인원수로 변경
        if (param)
            setLimit(param);
        else
            notEnoughParams(client->getSocket(), client->getNickname(), "MODE"); //수정 필요
    }
    else
        throw std::runtime_error("no such mode");
    channel->setMode(mode);
}

void Server::removeChannelMode(std::string channelName, ChannelMode mode, std::string param)
{
    //mode에 따라서 채널 모드 변경. 채널 모드에 따라 액션 실행 필요
    channels[channelName]->removeMode(mode);
}
