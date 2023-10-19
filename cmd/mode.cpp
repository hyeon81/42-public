#include "../Server.hpp"

bool checkModeArgu(std::string &argu)
{
    //모드가 플러스인지 마이너스인지 확인
    char oper = argu[0];
    if (oper != '+' && oper != '-')
        return (false);
    //유효한 모드인지 확인
    return (true);
}

//MODE 채널명 모드명 [모드매개변수]
void Server::mode(MessageInfo *msg, Client *client)
{
    if (!msg->params.size())
    {
        notEnoughParams(client->getSocket(), client->getNickname(), "MODE");
        return ;
    }
    //채널 모드 변경
    //맨처음 인자가 채널인지 확인
    std::string channelName = msg->params[0];
    //:root!root@127.0.0.1 MODE root :+i
    if (channelName[0] != '#')
        return;

    if (!isExistChannel(channelName))
        noSuchChannel(client->getSocket(), client->getNickname(), channelName);

    if (!(channels[channelName]->isMember(client)))
        MeNotOnChannel(client, channelName);

    //인자가 하나만 있을 경우. 즉 채널명만 있을 경우
    if (msg->params.size() == 1)
    {
        std::string channelModes = getChannelModes(channelName);
        if (channelModes.length() == 1 && channelModes[0] == '+')
            return ;
        std::string msg = ":ft_irc 324 " + client->getNickname() + " " + channelModes;
        sendResponse(msg, client);
        return ;
    }

    //인자가 두개인데, 두번째 인자가 모드인지 확인
    if (!checkModeArgu(msg->params[1]))
    {
        //유효한 모드 인자 아님
        std::string msgs = ":ft_irc 403 " + client->getNickname() + " " + msg->params[1] + " :is unknown mode char to me";
        sendResponse(msgs, client);
        return ;
    }
    std::string modeArgu;
    if (msg->params.size() == 3)
        modeArgu = msg->params[2];

    std::string modeString = msg->params[1];
    char modeOption[5] = {'i', 't', 'k', 'o', 'l'};
    ChannelMode modeEnum[5] = {INVITE, TOPIC, KEY, OPER, LIMIT};

    //하나에 대해서 실행
    for (unsigned long j = 1; j < modeString.length(); j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (modeString[j] == modeOption[i])
            {
                //모드 적용
                if (msg->params[1][0] == '+')
                    setChannelMode(channelName, modeEnum[i], modeArgu, client);
                else if (msg->params[1][0] == '-')
                    removeChannelMode(channelName, modeEnum[i], modeArgu, client);
                break;
            }
            if (i == 5)
            {
                //유효한 모드 인자 아님
                std::string msgs = ":ft_irc 403 " + client->getNickname() + " " + modeString[j] + " :is unknown mode char to me";
                sendResponse(msgs, client);
            }
        }
    }
    
}

// Command: MODE
// Parameters: <target> [<modestring> [<mode arguments>...]]
void Server::setChannelMode(std::string channelName, ChannelMode mode, std::string param, Client *client)
{
    Channel *channel = channels[channelName];
    if (channel->isOperator(client->getSocket()) == false)
        noChannelOperPrivileges(client->getSocket(), client->getNickname(), channelName);
    
    if (mode != OPER && mode != LIMIT && channel->isModeApplied(mode))
        return ;
    
    //MODE hello +i dkd
    if (mode == INVITE)
    {
        if (channel->isModeApplied(INVITE))
            return ;
        
        //:root!root@127.0.0.1 MODE #hello :-i
        std::string msg = "MODE " + channelName + " :+i";
        sendMessageAll(client, msg, channelName);
    }

    //Set/remove the restrictions of the TOPIC command to channel operators (TOPIC 명령어의 제한 두는 것을set/remove)
    else if (mode == TOPIC) 
    {
        //:root_!root@127.0.0.1 MODE #hello :+t
        std::string msg = "MODE " + channelName + " :+t";
        sendMessageAll(client, msg, channelName); 
    }

    //:root_!root@127.0.0.1 MODE #hello +k :hi
    else if (mode == KEY)
    {
        if (param.empty())
            invalidModeParam(client, channelName, "k *");
        else
        {
            channel->setKey(param);
            std::string msg = "MODE " + channelName + " +k :" + param;
            sendMessageAll(client, msg, channelName);
        }
    }
    
    //MODE #hello +o root
    //:root_!root@127.0.0.1 MODE #hello +o :root
    //:irc.local 401 root_ djkdlsf :No such nick
    //:irc.local 696 root_ #hello o * :You must specify a parameter for the op mode. Syntax: <nick>
    else if (mode == OPER)
    {
        //:irc.local 696 root_ #hello o * :You must specify a parameter for the op mode. Syntax: <nick>
        if (param.empty())
            invalidModeParam(client, channelName, "o *");
        else
        {
            Client *user = getClient(param); 
            if (!user)
                noSuchNick(client->getSocket(), client->getNickname(), param);
            
            //inviteClient
            if (channel->isOperator(user->getSocket()))
                return ;
            
            if (!(channel->isMember(user)))
                notOnChannel(client, channelName, user->getNickname());
            
            channel->addOperator(user);
            //:root_!root@127.0.0.1 MODE #hello +o :root
            std::string msg = "MODE " + channelName + " +o :" + param;
            sendMessageAll(client, msg, channelName);
        }
    }
    else if (mode == LIMIT)
    {
        //param에 해당하는 인원수로 변경
        if (param.empty())
        {
            invalidModeParam(client, channelName, "l *");
            return ;
        }
        else
        {
            int limit = strtod(param.c_str(), NULL);
            //:root_!root@127.0.0.1 MODE #hello +l :123
            //가능한 숫자가 아닌경우
            if (limit < 0)
            {
                std::string modStr = "l " + param;
                invalidModeParam(client, channelName, modStr);
                return ;
            }
            channel->setLimit(limit);
            std::string msg = "MODE " + channelName + " +l :" + param;
            sendMessageAll(client, msg, channelName);
        }
    }
    channel->setMode(mode);
}

void Server::removeChannelMode(std::string channelName, ChannelMode mode, std::string param, Client *client)
{
    Channel *channel = channels[channelName];
    if (!channel->isModeApplied(mode))
        return ;
    if (mode == INVITE)
    {
        //:root_!root@127.0.0.1 MODE #hello :-i
        std::string msg = "MODE " + channelName + " :-i";
        sendMessageAll(client, msg, channelName);
    }
    else if (mode == TOPIC)
    {
        std::string msg = "MODE " + channelName + " :-t";
        sendMessageAll(client, msg, channelName);
    }
    else if (mode == KEY)
    {
        //키 모드
        //:root_!root@127.0.0.1 MODE #hello -k :123
        std::string msg = "MODE " + channelName + " -k :" + channel->getKey();
        sendMessageAll(client, msg, channelName);
    }
    else if (mode == OPER)
    {
        //:root_!root@127.0.0.1 MODE #hello -o :root
        //param에 해당하는 클라이언트를 오퍼레이터로 변경
        if (param.empty())
        {
            invalidModeParam(client, channelName, "o *");
            return ;
        }
        else
        {
            Client *user = getClient(param);
            if (!user)
                noSuchNick(client->getSocket(), client->getNickname(), param);
            
            if (!channel->isOperator(user->getSocket()))
                throw std::runtime_error("not operator");
            
            if (!(channel->isMember(user)))
                notOnChannel(client, channelName, user->getNickname());
            
            //:root_!root@127.0.0.1 MODE #hello -o :root_
            channel->removeOperator(user);
            std::string msg = "MODE " + channelName + " -o :" + param;
            sendMessageAll(client, msg, channelName);
        }
    }
    else if (mode == LIMIT)
    {
        channel->removeLimit();
        std::ostringstream oss;
        oss << channel->getLimit();
        std::string result = oss.str();
        std::string msg = "MODE " + channelName + " -l :" + result;
        sendMessageAll(client, msg, channelName);
    }
    channels[channelName]->removeMode(mode);
}
