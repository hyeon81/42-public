#include "../Server.hpp"

//PRIVMSG
//ex: "/privmsg msgtarget :message"
//<target>사용자이고 해당 사용자가 자리 비움으로 설정된 경우 서버는 숫자로 응답할 수 있으며 명령은 계속됩니다
//메시지 PRIVMSG는 서버에서 클라이언트로 전송되어 해당 클라이언트에 메시지를 전달합니다.
/*
    사용자간에 비공개 메세지를 보내고 채널에 메시지를 보내는 데 사용된다
    Command: PRIVMSG
    Parameters: <target>{,<target>} <text to be sent>
    target 은 채널 이름이나 클라이언트의 별명 
  */


void Server::privmsg(MessageInfo *msg, Client *client)
{
    if(!msg->params.size())
        notEnoughParams(client->getSocket(), client->getNickname(), "");
    if(msg->params[0][0] == '#') //channel 브로드 캐스트 // 개별적으로..
    {
        if(isExistChannel(msg->params[0]))
            sendMessageAll(client, msg->params[1], msg->params[0]);
        else
            noSuchChannel(client->getSocket(), client->getNickname(), msg->params[0]);
    }
    else //client 401
    {
        Client *targetClient = getClient(msg->params[0]);
        if(targetClient)
        {
            std::string sendMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + "PRIVMSG " + msg->params[1];
            sendResponse(sendMsg, client);
        }
        else
            // sendResponse(client->getNickname() + "No such nick", client);
            noSuchNick(client->getSocket(), client->getNickname(), msg->params[0]);
    }
    ;
}
