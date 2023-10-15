#include "../Server.hpp"

/*

     명령: NICK
   매개변수: <닉네임> [ <홉수> ]

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




void Server::nick(MessageInfo &msg, Client *client)
{
    /*먼저 클라이언트가 초기화되었는지 확인
    클라이언트가 초기화되지 않았다면 (즉, 처음 연결될 때), 새로운 닉네임을 설정하고 초기 환영 메시지를 전송
    
        nickname이 없을 때, 어떤 일이 일어나는지 확인하기. 예를 들어, nickname 설정 안하고 채팅하면 username 나오는데 설정하고 나면 nickname으로
        나온다던지 요런거 체크하가.
    
     */
    // std::cout << "nick" << std::endl;
    std::string errorMsg;
    if (!msg.params.size()) // 아무것도 안들어오면 그냥 무시 
    {
        //ERR_NONICKNAMEGIVEN (431) 
        //"<client> :No nickname given" // Error: parameters error\r\n
        errorMsg = "ft_irc 431 :No nickname given";
        sendResponse(errorMsg, client);
        throw std::runtime_error("no nickname given");
    }
    std::string nickName = msg.params[0];
    if(nickName.length() > 9) // 9를 초과할 경우 
    {
        //ERR_ERRONEUSNICKNAME (432) 
        //"<client> <nick> :Erroneus nickname"
        errorMsg = "ft_irc 432 " + nickName + " :Erroneus nickname";
        sendResponse(errorMsg, client);
        throw std::runtime_error("erroneus nickname");
    }

    for (size_t i = 0; i < nickName .length(); ++i) // 허용되지 않은 문자가 있는 경우
    { 
        char c = nickName [i]; //영숫자 대괄호( []{}), 백슬래시( \) 및 파이프( |) 문자를 허용
        if (!(isalnum(c) || c == '[' || c == ']' || c == '{' || c == '}' || c == '\\' || c == '|'))
        {
            errorMsg = "ft_irc 432 " + nickName + " :Erroneus nickname";
            sendResponse(errorMsg, client);
            throw std::runtime_error("erroneus nickname");
        }
    }

    for(std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
    {//같은 nick이 있을 경우 있다고 알려야하나 에러를 내보내야하나
        if (it->second->getNickname() == nickName)
        {
            //ERR_NICKNAMEINUSE (433) 
            //"<client> <nick> :Nickname is already in use"
            errorMsg = "ft_irc 433 " + nickName + " :Nickname is already in use";
            sendResponse(errorMsg, client);
            throw std::runtime_error("nickname is already in use");
        }
    }

    // std::string oldNick = client.getNickname();
    //출력 -> :닉네임!사용자이름@IP NICK :새로운닉네임

	std::string responseMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 NICK :" + nickName;
    sendResponse(responseMsg, client);
    client->setNickname(nickName);

    //sendNicknameChangeToAllClients(oldNick, nickName); 모든 유저에게 알려야하나?
}

