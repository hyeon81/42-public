#include "../Server.hpp"

bool checkModeArgu(std::string &argu)
{
    //모드가 플러스인지 마이너스인지 확인
    if (argu.size() != 2)
        return (false);
    char oper = argu[0];
    if (oper != '+' && oper != '-')
        return (false);
    //유효한 모드인지 확인
    char modeChar = argu[1];
    if (modeChar != 'i' && modeChar != 't' && modeChar != 'k' && modeChar != 'o' && modeChar != 'l')
        return (false);
    return (true);
}

//MODE 채널명 모드명 [모드매개변수]
//MODE 모드명도 가능한듯 - 이건 나중에 확인
//권한 있는지 없는지 확인해야
void Server::mode(MessageInfo &msg, Client *client)
{
    if (!msg.params.size())
    {
        notEnoughParams(client->getSocket(), client->getNickname(), "MODE");
        return ;
    }
    //채널 모드 변경
    //맨처음 인자가 채널인지 확인
    std::string channelName = msg.params[0];
    if (!isExistChannel(channelName))
    {
        noSuchChannel(client->getSocket(), client->getNickname(), channelName);
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
        std::string msgs = ":ft_irc 403 " + client->getNickname() + " " + msg.params[1] + " :is unknown mode char to me";
        sendResponse(msgs, client);
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
            if (msg.params[1][0] == '+')
                setChannelMode(channelName, modeEnum[i], modeArgu, client);
            else if (msg.params[1][0] == '-')
                removeChannelMode(channelName, modeEnum[i], modeArgu, client);
        }
    }
}

// Command: MODE
// Parameters: <target> [<modestring> [<mode arguments>...]]
//내 생각엔 앞의 + -를 가져와서 같이 처리해야 할듯.
//근데 operator가 있어야 mode도 가능한가?
//channelName = param[0], param = params[2]
//모드 설정할때 response 보내나?
void Server::setChannelMode(std::string channelName, ChannelMode mode, std::string param, Client *client)
{
    Channel *channel = channels[channelName];
    if (channel->isOperator(client->getSocket()) == false)
    {
        channelOperatorPrivilegesNeeded(client->getSocket(), client->getNickname(), channelName);
        return ;
    }
    if (mode != OPER && mode != LIMIT && channel->isModeApplied(mode))
        return ;
    //mode에 따라서 채널 모드 변경. 채널 모드에 따라 액션 실행 필요
    //이미 채널에 있는 상태여야 함.
    //param에 해당하는 클라이언트를 초대
    //MODE hello +i dkd
    if (mode == INVITE)
    {
        if (channel->isModeApplied(INVITE))
            return ;
        // if (param.empty() == false)
            // return ;
            // params이 있을시
            // /mode +i hello 이렇게 보내면? 뒤의 hello를 붙여서 보냄
            // 여러 인자를 처리해줘야겠다.
            // 127.000.000.001.06667-127.000.000.001.37866: :irc.local 472 root h :is not a recognised channel mode.
            // :irc.local 472 root e :is not a recognised channel mode.
            // :irc.local 696 root #hello l * :You must specify a parameter for the limit mode. Syntax: <limit>.
        //없으면?
        //오류없다는 것이므로 +i로 set이 된다.
        //mode가 set 되었다는 메세지 전송
        //:root!root@127.0.0.1 MODE #hello :-i
        std::string msg = "MODE " + channelName + " :+i";
        sendMessageAll(client, msg);
    }
    //Set/remove the restrictions of the TOPIC command to channel operators (TOPIC 명령어의 제한 두는 것을set/remove)
    else if (mode == TOPIC) 
    {
        //2. 채널 이름이 맞다면? operator 전용으로 변경 (mode의 topic이 1이라는건? topic을 operator만 제한한다는 걸로 받아들이기. 고로 여기서 설정해줄건x)
        //:root_!root@127.0.0.1 MODE #hello :+t
        std::string msg = "MODE " + channelName + " :+t";
        sendMessageAll(client, msg); 
    }
    //:root_!root@127.0.0.1 MODE #hello +k :hi
    //한번 적용되면 바꿀 수 없나벼
    else if (mode == KEY)
    {
        if (param.empty())
            invalidModeParam(client, channelName, "k *");
        else
        {
            //키가 규칙에 맞는지 체크해야함. 어디서 볼수있지?
            channel->setKey(param);
            std::string msg = "MODE " + channelName + " +k :" + param;
            sendMessageAll(client, msg);
        }
    }
    //MODE #hello +o root
    //:root_!root@127.0.0.1 MODE #hello +o :root
    //:irc.local 401 root_ djkdlsf :No such nick
    //:irc.local 696 root_ #hello o * :You must specify a parameter for the op mode. Syntax: <nick>
    else if (mode == OPER)
    {
        //2. param에 해당하는 클라이언트를 오퍼레이터로 변경 (op_client에 포함시키기)
        ///MODE #irssi +o mike
        //유저 파라미터가 없는 경우
        //:irc.local 696 root_ #hello o * :You must specify a parameter for the op mode. Syntax: <nick>
        //"<client> <target chan/user> <mode char> <parameter> :<description>"
        if (param.empty())
        {
            invalidModeParam(client, channelName, "o *");
            // notEnoughParams(client->getSocket(), client->getNickname(), "MODE"); //수정 필요
            return ;       
        }
        else
        {
            Client *user = getClient(param); //없는 유저면 throw 되려나?
            if (!user)
                noSuchNick(client->getSocket(), client->getNickname(), param);
            //inviteClient
            //중복되는 유저면 ? 무시
            if (channel->isOperator(user->getSocket()))
                return ;
            channel->addOperator(user);
            //이후 클라이언트에게 operator 메시지 전송
            //:root_!root@127.0.0.1 MODE #hello +o :root
            std::string msg = "MODE " + channelName + " +o :" + param;
            sendMessageAll(client, msg);     
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
            std::string msg = "MODE " + channelName + " +o :" + param;
            sendMessageAll(client, msg);
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
        sendMessageAll(client, msg);
    }
    else if (mode == TOPIC)
    {
        std::string msg = "MODE " + channelName + " :-t";
        sendMessageAll(client, msg);
    }
    else if (mode == KEY)
    {
        //키 모드
        //:root_!root@127.0.0.1 MODE #hello -k :123
        std::string msg = "MODE " + channelName + " -k :" + getKey();
        sendMessageAll(client, msg);
    }
    else if (mode == OPER)
    {
        //1. 채널 이름이 맞는지 확인
        //2. param에 해당하는 클라이언트를 오퍼레이터로 변경 (op_client에 포함시키기)
        //:root_!root@127.0.0.1 MODE #hello -o :root
        //param에 해당하는 클라이언트를 오퍼레이터로 변경
        if (param.empty())
        {
            invalidModeParam(client, channelName, "o *");
            return ;
        }
        else
        {
            Client *user = getClient(param); //없는 유저면 throw 되려나?
            if (!user)
                noSuchNick(client->getSocket(), client->getNickname(), param);
            if (!channel->isOperator(user->getSocket()))
                throw std::runtime_error("not operator");
            //:root_!root@127.0.0.1 MODE #hello -o :root_
            channel->removeOperator(user);
            std::string msg = "MODE " + channelName + " -o :" + param;
            sendMessageAll(client, msg);
        }
    }
    else if (mode == LIMIT)
    {
        channel->removeLimit();
        std::ostringstream oss;
        oss << channel->getLimit();
        std::string result = oss.str();
        std::string msg = "MODE " + channelName + " -l :" + result;
        sendMessageAll(client, msg);
    }
    channels[channelName]->removeMode(mode);
}
