#include "../Server.hpp"
/*
   NICK 메시지는 사용자에게 닉네임을 부여하거나 이전 이름을 변경하는 데 사용됩니다.
   하나. <hopcount> 매개변수는 서버에서 표시하기 위해서만 사용됩니다.
   닉이 홈 서버에서 얼마나 멀리 떨어져 있는지. 로컬 연결에는
   홉 수는 0입니다. 클라이언트가 제공한 경우 무시해야 합니다.

   NICK 메시지가 이미 알고 있는 서버에 도착하면
   다른 클라이언트의 닉네임이 동일하면 닉네임 충돌이 발생합니다.
   닉네임 충돌로 인해 닉네임의 모든 인스턴스가
   서버의 데이터베이스에서 제거되고 KILL 명령이 실행됩니다.
   다른 모든 서버의 데이터베이스에서 별명을 제거합니다. 만약 NICK
   충돌을 일으킨 메시지는 닉네임 변경이었고,
   원래(이전) 닉도 제거해야 합니다.

   서버가 클라이언트로부터 동일한 NICK를 수신하는 경우
   직접 연결되어 있으면 로컬에 ERR_NICKCOLLISION이 발생할 수 있습니다.
   클라이언트에서는 NICK 명령을 삭제하고 킬을 생성하지 마십시오.

*/





//NICK root
//NICK

//127.000.000.001.06667-127.000.000.001.52376: :root!root@127.0.0.1 NICK :eunjiko

//root!root@127.0.0.1 NICK :eunjiko

//nick

//Irssi: Your nickname is eko
//user username hostname asdf realname
//127.000.000.001.52376-127.000.000.001.06667: NICK eko
//eunjiko!root@127.0.0.1 NICK :eko
//:닉네임!사용자이름@IP NICK :새로운닉네임
//'prefix'              'command params' 'crlf'
//maximum (9)
//중복이 되는경우가 다른 클라이언트랑 중복이 되는경우


//이미 있는 유저가 들어오면..?





void Server::nick(MessageInfo *msg, Client *client)
{
    std::string errorMsg;
    if (!msg->params.size()) 
    {
        errorMsg = "ft_irc 431 :No nickname given";
        sendResponse(errorMsg, client);
        return ;
        // throw std::runtime_error("no nickname given");
    }
    std::string nickName = msg->params[0];
    if (nickName.length() > 9)
    {
        errorMsg = "ft_irc 432 " + nickName + " :Erroneus nickname";
        sendResponse(errorMsg, client);
        return ;
    }
    for (size_t i = 0; i < nickName.length(); ++i) // 허용되지 않은 문자가 있는 경우
    { 
        char c = nickName [i];
        if (!(isalnum(c) || c == '[' || c == ']' || c == '{' || c == '}' || c == '\\' || c == '|'))
        {
            errorMsg = ":ft_irc 432 " + nickName + " :Erroneus nickname";
            sendResponse(errorMsg, client);
            return ;
        }
    }

    // if(client->getNickname().empty()) //들어올때 hello로 들어오기때문에
    // {
    //     for(std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
    //     {
    //         if (it->second->getNickname() == nickName) // 같을 경우만 검증을 하기 때문
    //         {
                

    //             client->setNickname(nickName + "_");
    //             return ;
    //         }


            
    //     }
    //     client->setNickname(nickName);
    //     return ;
    // }

    if (client->getNickname().empty()) // 새로운 클라이언트의 경우
    {
        // 동일한 닉네임이 이미 존재하는지 확인
        for (std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
        {
            if (it->second->getNickname() == nickName)
            {
                // 이미 사용 중인 닉네임이라면 언더스코어 추가
                int underscoreCount = 1;
                std::string originalName = nickName;
                while (clientExistsWithNickname(nickName))
                {
                    nickName = originalName + "_";
                    for (int i = 0; i < underscoreCount; ++i)
                    {
                        nickName += "_";
                    }
                    underscoreCount++;
                }
                break;
            }
        }
        client->setNickname(nickName);
    }

    else
    {
        for(std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); it++)
        {
            if (it->second->getNickname() == nickName) // 같을 경우
            {
                std::string responseMsg = ":ft_irc 433 " + client->getNickname() + " " + nickName + " :Nickname is already in use.\r\n";
                sendResponse(responseMsg, client);
                return ;
            }
        }
    }
    std::string responseMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 NICK :" + nickName;
    sendResponse(responseMsg, client);
    client->setNickname(nickName);
}

//퀴트할때 이미 참여하고 있음 더 들어갈수없게 만들기