#include "Server.hpp"

void Server::runCommand(MessageInfo &msg, Client &client)
{
    try {
        void (Server::*funcs[13])(Client &client, MessageInfo &msg) = {&Server::pass, &Server::nick, &Server::user, &Server::join,
                                            &Server::part, &Server::names, &Server::topic, &Server::list,
                                            &Server::invite, &Server::kick, &Server::mode, &Server::privmsg,
                                            &Server::notice};
        std::string cmds[13] = {"PASS", "NICK", "USER", "JOIN", "PART", "NAMES", "TOPIC", "LIST", "INVITE", "KICK", "MODE", "PRIVMSG", "NOTICE"};

        for (int i = 0; i < 13; i++)
        {
            if (cmds[i] == msg.command)
            {
                (this->*funcs[i])(msg, client);
                return;
            }
        }
        //명령어가 없을 경우. 빼도 됨.
        throw std::runtime_error("no match command");
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

//PASS 0801
void Server::pass(MessageInfo &msg, Client &client)
{
    std::cout << "pass" << std::endl;
    //비밀번호가 일치하는지 확인
    if (!msg.params.size())
        return;
    const clientPw = msg.params[0];
    if (clientPw == this->password)
    {
        std::cout << "isValid" << std::endl;
        client.setValid(true);
    }
}

//NICK root
void Server::nick(MessageInfo &msg, Client &client)
{
    std::cout << "nick" << std::endl;
    //닉네임이 일치하는지 확인. params가 없으면 무시.
    if (!msg.params.size())
        return;
    const nickname = msg.params[0];
    //중복되지 않는지 체크 필요
    client.setNickname(nickname);
}

//USER root root 127.0.0.1 :root
//<username> <hostname> <servername> <realname>
//1번째랑 4번째만 사용
void Server::user(MessageInfo &msg, Client &client)
{
    std::cout << "user" << std::endl;
    //유저일때는 parmas 없어도 응답 보냄.
    if (!msg.params.size())
    {
        //오류 메세지 보내기
    }
    std::string username = msg.params[0];
    if (msg.params.size() > 4)
        std::string realname = msg.params[3];
    //인자가 덜 들어왔을때 처리 확인 필요
    //username, realname이 겹칠 경우 조치 필요
    client.setUsername(username, realname);
    //유저가 들어왔을때 client 등록한다고 판단. pass와 nick이 먼저 들어와야함.
    addClient(client);
}

/***Channel Command ***/

//JOIN #test
//추후에 쉼표도 처리
void Server::join(MessageInfo &msg, Client &client)
{
    std::cout << "join" << std::endl;
    //params가 있는지 확인
    if (!msg.params.size())
        return;
    //채널이 있는지 확인. 있는 채널이면 그 채널로, 없는 채널이면 새로 생성한다.
    /* #제거하고 찾아!!! */
    if (isExistChannel(msg.params[0]))
    {
        //채널에 클라이언트 추가
        addClientToChannel(msg.params[0], client);
    }
    else
    {
        //채널 생성
        addChannel(msg.params[0]);
        //채널에 클라이언트 추가
        addClientToChannel(msg.params[0], client);
        //해당 클라이언트를 operator로 설정
        setOperatorFd(client.getSocket());
    }
}

//PART #test
void Server::part(MessageInfo &msg, Client &client)
{
    if (!msg.params.size())
        return;
    if (isExistChannel(msg.params[0]))
    {
        //채널에 클라이언트 제거
        removeClientFromChannel(msg.params[0], client);
        //해당 클라이언트가 operator이면 다른 클라이언트를 operator로 설정?
        if (isOperator(client.getSocket()))
        {
            //다른 클라이언트를 operator로 설정
            //얘가 마지막 클라이언트면 채널 제거
        }
    }
}

//NAMES #test
void Server::names(MessageInfo &msg, Client &client)
{
    //해당 채널의 사람들의 목록을 보여줌
}

//TOPIC #test
void Server::topic(Client &client, MessageInfo &msg)
{

}

//LIST
void Server::list(MessageInfo &msg, Client &client)
{

}

//INVITE
void Server::invite(MessageInfo &msg, Client &client)
{

}

//KICK
void Server::kick(MessageInfo &msg, Client &client)
{

}

//MODE
void Server::mode(MessageInfo &msg, Client &client)
{

}

//PRIVMSG
void Server::privmsg(MessageInfo &msg, Client &client)
{

}

void Server::notice(MessageInfo &msg, Client &client)
{

}
