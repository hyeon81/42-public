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
    //ㅇㅇ 메시지 유효성 검사랑 명령어 유효성 검사는 다르니까
    //명령어 실행하는데 있어서 유효성 검사하는건 server 책임
    //정책검사는 뭘 말하는진 모르겠지만 서버 자체 규칙이 있으면 뭐..
    //ㅇㅇㅇㅇ 중복검사 ㄱㄷ
    // 아 이거 있네
    //    <nick>       ::= <letter> { <letter> | <number> | <special> }
    //그치 이건 명령어 유효성 검사에 해당하는거지
    //인자 확인하고 정상적인지 아닌지니까
    //   <special>    ::= '-' | '[' | ']' | '\' | '`' | '^' | '{' | '}'
    //ㅇㅇㅇ 저것들 중에서 근데 말했다시피 규약이 다 나와있는거라 구현은 간단함
    //그치 귀찮은게 문제지ㅋㅋㅋㅋㅋㅋㅋㅋ
    //음..꿀팁?은 잘모르겠고
    //애매하다 싶으면 IRC Protocol 보면 됨
    //https://datatracker.ietf.org/doc/html/rfc1459#section-2.3
    //허용 = 가능함
    //안 써있음 = 처리 안해도 됨
    //MUST = 무조건 하셈 
    //SHOULD = 가능하면 하셈 = 안해도 됨
    //may = 해도 되고 안 해도 되고 = 안해도 됨
    //may not = 안 하는게 기본인데 해도 됨 = 안해도 됨
    //근데 이런 수식어 없으면 구현하는게 기본이라 생각하면 됨
    //irssi 그 connect였나? 거기에 옵션으로 다 넣는거임
    //nick user pass 순서는 기억 안 나는데 암튼 옵션 넣는걸로 기억함
    //connect ㅇㅇㅇ
    //? 보여줘봐 화면공유좀 ㅇㅎ

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
