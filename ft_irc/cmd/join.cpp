#include "../Server.hpp"

//JOIN #test

void Server::join(MessageInfo *msg, Client *client) 
{
    if (!msg->params.size()) {
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
    }

    std::string channelName = msg->params[0];
    if (client->getCurrentchannel() != "*")
    {
        std::string sendMsg = ":ft_irc 405 " + client->getNickname() + " " + channelName + " :You have joined too many channels";
        sendResponse(sendMsg, client);
        throw std::runtime_error("too many channels");
    }

    if (channelName[0] != '#' && channelName[0] != '&') 
    {
        std::string msg = ":ft_irc 476 " + client->getNickname() + " " + channelName + " :Bad Channel Mask";
        sendResponse(msg, client);
        throw std::runtime_error("bad channel mask");
    }
    if (isExistChannel(channelName)) {
        std::string password = "";

        if (msg->params.size() == 2) {
            password = msg->params[1];
        }
        addClientToChannel(channelName, client, password);
        client->setCurrentchannel(channelName);

        std::string joinMessage = ":" + client->getNickname() + "!" + client->getUsername()
                + "@127.0.0.1 JOIN :" + channelName;
        sendResponse(joinMessage, client);

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
        client->setCurrentchannel(channelName);//
        
        // 새로운 채널에 클라이언트가 참가했음을 다른 사용자에게 알린다
        std::string joinMessage = ":" + client->getNickname() + "!" + client->getUsername()
                + "@127.0.0.1 JOIN :" + channelName;
        sendResponse(joinMessage, client);

        // JOIN 명령의 끝을 알리는 메시지
        std::string endMessage = ":ft_irc 366 " + client->getNickname() + " " + channelName + " :End of /NAMES list.";
        sendResponse(endMessage, client);
    }
}
