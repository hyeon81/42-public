#include "../Server.hpp"

/*
Command: WHO
Parameters: <mask>

ex
WHO emersion        ; request information on user "emersion"
WHO #ircv3          ; list users in the "#ircv3" channel

mask
채널 이름. 이 경우 채널 구성원이 나열됩니다.
정확한 별명. 이 경우 단일 사용자가 반환됩니다.
닉네임이 일치하는 모든 표시 사용자가 나열되는 마스크 패턴입니다. 서버는 호스트 이름, 서버, 실제 이름 또는 사용자 이름과 같은 다른 사용자별 값과 일치할 수 있습니다. 서버는 마스크 패턴을 지원하지 않고 빈 목록을 반환할 수 있습니다.


*/

/*
127.000.000.001.06667-127.000.000.001.35666: :irc.local 352 root_ * root 127.0.0.1 irc.local root_ H :0 root
:irc.local 352 root_ * root 127.0.0.1 irc.local root H :0 root
:irc.local 315 root_ root :End of /WHO list.
*/


//352 클라이언트의 정보
//315 정보의 끝

void Server::who(MessageInfo *msg, Client *client)
{//msg 다시 세팅 

    std::string sendMsg = "";
    if(msg->params[0][0] == '#') //channel
    {
        if(isExistChannel(msg->params[0]))
        {
            std::vector<Client*> members = getChannel(msg->params[0])->getChannelMembers();
            for (size_t i = 0; i < members.size(); i++)
            {
                /*
                eko가 물어봄
            :irc.local 352 eko #hello root 127.0.0.1 irc.local _nick H :0 root
            :irc.local 352 eko #hello root 127.0.0.1 irc.local eko H@ :0 root
            :irc.local 352 eko #hello root 127.0.0.1 irc.local root H :0 root
            :irc.local 315 eko #hello :End of /WHO list.
                */
                sendMsg = ":ft_irc 352" + client->getNickname() + " " + msg->params[0] + " " +
                client->getUsername() + "127.0.0.1 " + "ft_irc" + members[i]->getNickname() + "H :0" + members[i]->getUsername();
                sendResponse(sendMsg, client); //host면 @
            }
            sendMsg = ":ft_irc 315" + client->getNickname() + " " + msg->params[0] + " :End of /WHO list.";
            sendResponse(sendMsg, client);
        }
        else
            noSuchChannel(client->getSocket(), client->getNickname(), msg->params[0]);
    }
    else //client
    {
        Client *targetClient = getClient(msg->params[0]);
        if(targetClient)
        {
            /*
:irc.local 352 _nick #hello root 127.0.0.1 irc.local _nick H :0 root
:irc.local 315 _nick _nick :End of /WHO list.
채팅방에 없을 때 마찬가지로 호스트일땐 골뱅이에 @
:irc.local 352 _nick * root 127.0.0.1 irc.local _nick H :0 root
:irc.local 315 _nick _nick :End of /WHO list.
            */
            sendMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + \
                    "WHO" + targetClient->getNickname() + " " + targetClient->getUsername();
            sendResponse(sendMsg, client);
        }
        else
            noSuchNick(client->getSocket(), client->getNickname(), msg->params[1]);
    }
}
