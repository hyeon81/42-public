#include "Server.hpp"

void Server::runCommand(MessageInfo &msg, Client &client)
{
    void (Server::*funcs[13])(Client &client, MessageInfo &msg) = {&Server::pass, &Server::nick, &Server::user, &Server::join,
                                            &Server::part, &Server::names, &Server::topic, &Server::list,
                                            &Server::invite, &Server::kick, &Server::mode, &Server::privmsg,
                                            &Server::notice};
    std::string cmds[13] = {"PASS", "NICK", "USER", "JOIN", "PART", "NAMES", "TOPIC", "LIST", "INVITE", "KICK", "MODE", "PRIVMSG", "NOTICE"};

    for (int i = 0; i < 13; i++)
    {
        if (cmds[i] == msg.command)
        {
            (this->*funcs[i])(client, msg);
            return;
        }
    }
    //일치하는 명령어가 없음
    std::cout << "no match command" << std::endl;
}

//PASS 0801
void Server::pass(Client &client, MessageInfo &msg)
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
void Server::nick(Client &client, MessageInfo &msg)
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
void Server::user(Client &client, MessageInfo &msg)
{
    std::cout << "user" << std::endl;
    //유저일때는 parmas 없어도 응답 보냄.
    if (!msg.params.size())
    {
        //오류 메세지 보내기
    }
    const nickname = msg.params[0];
    //인자가 덜 들어왔을때 처리 확인 필요
    client.setUsername(nickname);
}

void Server::join(Client &client, MessageInfo &msg)
{

}

void Server::part(Client &client, MessageInfo &msg)
{

}

void Server::names(Client &client, MessageInfo &msg)
{

}

void Server::topic(Client &client, MessageInfo &msg)
{

}

void Server::list(Client &client, MessageInfo &msg)
{

}

void Server::invite(Client &client, MessageInfo &msg)
{

}

void Server::kick(Client &client, MessageInfo &msg)
{

}

void Server::mode(Client &client, MessageInfo &msg)
{

}

void Server::privmsg(Client &client, MessageInfo &msg)
{

}

void Server::notice(Client &client, MessageInfo &msg)
{

}
