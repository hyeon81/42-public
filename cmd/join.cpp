#include "../Server.hpp"

//JOIN #test

//사용자의 별명/사용자 이름/호스트 이름은 어떤 것과동 ㅣㄹ치해서는 안된다
//설정된 경우 올바른 키를 입력

//가입하면 모든 알림을 받는다 -> join 명령은 모든 서버에 브로드캐스트가 되어 각 서버가 채널에 있는 사용자를 어디서 찾을 수 있는지 알고있음
//이를통해 privmsg/notice 메시지를 채널에 최적으로 전달

//성공하면 주제 전송



//#으로 시작하는지 확인

/*

채널 참여: JOIN 명령은 클라이언트가 특정 채널에 참여할 수 있게 합니다. 클라이언트는 JOIN 명령을 통해 참여하려는 채널의 이름을 지정합니다.

채널 생성: 만약 채널이 존재하지 않는 경우, 서버는 채널을 생성하고 클라이언트를 해당 채널의 멤버로 추가합니다.

채널 비밀번호: JOIN 명령은 채널에 비밀번호가 설정되어 있는 경우 해당 비밀번호를 제공하여 채널에 참여할 수 있도록 합니다. 채널에 비밀번호가 설정되어 있지 않다면, 비밀번호는 무시됩니다.

클라이언트 목록 업데이트: JOIN 명령을 통해 채널에 참여한 클라이언트 목록이 업데이트됩니다. 서버는 이 목록을 유지하고 다른 클라이언트가 해당 채널의 사용자 목록을 조회할 때 사용합니다.

JOIN 메시지 전파: 서버는 JOIN 명령을 통해 채널에 참여한 클라이언트를 기존 채널 멤버에게 알립니다. 이를 통해 채널 내 대화에 참여한 사용자를 알 수 있습니다.


서버는 JOIN 명령을 수신하고 채널 참여 작업을 처리하며, JOIN 명령을 통해 클라이언트가 채널에 참여할 때, 해당 채널에 대한 정보를 업데이트하고 JOIN 메시지를 전파하여 다른 사용자에게 알리는 역할을 수행합니다.


*/


//채널 비밀번호: JOIN 명령은 채널에 비밀번호가 설정되어 있는 경우 해당 비밀번호를 제공하여 채널에 참여할 수 있도록한다
// 채널에 비밀번호가 설정되어 있지 않다면, 비밀번호는 무시

//채널이름이 #으로 시작하는지

//password는 join에서 유효한 채널로 들어갈때만 값이 적용된다 

//문서에 있는 응답에러 방식과 실제의 방식이 다를 수 있다




void Server::join(MessageInfo *msg, Client *client) 
{
    // std::cout << "join" << std::endl;

    if (!msg->params.size()) {
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
    }
    std::string channelName = msg->params[0];
    if (channelName[0] != '#' && channelName[0] != '&') 
    {
        std::string msg = ":ft_irc 476 " + client->getNickname() + " " + channelName + " :Bad Channel Mask";
        sendResponse(msg, client);
        throw std::runtime_error("bad channel mask");
    }
    // 채널이 이미 존재한다면
    if (isExistChannel(channelName)) {
        std::string password = "";

        if (msg->params.size() == 2) {
            password = msg->params[1];
        }
        addClientToChannel(channelName, client, password);

        // 새클라이언트가 채널에 참가했음을 알림
        std::string joinMessage = ":" + client->getNickname() + "!" + client->getUsername()
                + "@127.0.0.1 JOIN :" + channelName;
        sendResponse(joinMessage, client);

        /* 채널의 모든 멤버에게 새멤버를 알림
    모든 채널 멤버에게 멤버 리스트를 보냄: :@member1 member2 member3 ...
    클라이언트에게 JOIN 명령의 끝을 알리는 메시지 전송: :ft_irc 366 <client-nickname> channel1 :End of /NAMES list.
        */
        // 모든 멤버에게 멤버 리스트
        //127.000.000.001.06667-127.000.000.001.33894: :hey!root@127.0.0.1 JOIN :#hi
        //:irc.local 353 hey = #hi :@hey
        //:irc.local 366 hey #hi :End of /NAMES list
        std::string userList = ":ft_irc 353 " + client->getNickname() + " = " + channelName + " :@";
        std::vector<Client*> members = channels[channelName]->getChannelMembers();

        for (size_t i = 0; i < members.size(); i++) 
        {
            userList += members[i]->getNickname();
            if (i < members.size()) 
                userList += " ";
        }
        // userList += "\n";
        for (size_t i = 0; i < members.size(); i++) {
            sendResponse(userList, members[i]);
        }

        // JOIN 명령의 끝을 알리는 메시지
        std::string endMessage = ":ft_irc 366 " + client->getNickname() + " " + channelName + " :End of /NAMES list.";
        sendResponse(endMessage, client);
    } 
    else {// 채널이 존재하지 않는 경우 새로운 채널을 생성
        addChannel(channelName);
        addClientToChannel(channelName, client, "");

        // 필요한 경우 해당 클라이언트를 operator로 설정하는 코드를 추가
        channels[channelName]->setOperatorFd(client);
        
        // 새로운 채널에 클라이언트가 참가했음을 다른 사용자에게 알린다
        std::string joinMessage = ":" + client->getNickname() + "!" + client->getUsername()
                + "@127.0.0.1 JOIN :" + channelName;
        sendResponse(joinMessage, client);

        // JOIN 명령의 끝을 알리는 메시지
        std::string endMessage = ":ft_irc 366 " + client->getNickname() + " " + channelName + " :End of /NAMES list.";
        sendResponse(endMessage, client);
    }
}
