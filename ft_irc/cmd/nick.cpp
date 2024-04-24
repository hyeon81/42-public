#include "../Server.hpp"

void Server::nick(MessageInfo *msg, Client *client)
{
    std::string errorMsg;
    if (!msg->params.size()) 
    {
        errorMsg = "ft_irc 431 :No nickname given";
        sendResponse(errorMsg, client);
        return ;
    }
    std::string nickName = msg->params[0];
    if(nickName.length() > 9)
    {
        errorMsg = "ft_irc 432 " + nickName + " :Erroneus nickname";
        sendResponse(errorMsg, client);
        return ;
    }
    for (size_t i = 0; i < nickName .length(); ++i) // 허용되지 않은 문자가 있는 경우
    { 
        char c = nickName [i];
        if (!(isalnum(c) || c == '[' || c == ']' || c == '{' || c == '}' || c == '\\' || c == '|'))
        {
            errorMsg = ":ft_irc 432 " + nickName + " :Erroneus nickname";
            sendResponse(errorMsg, client);
            return ;
        }
    }

    if (client->getNickname().empty()) // 새로운 클라이언트의 경우
    {
        // 동일한 닉네임이 이미 존재하는지 확인
        for (std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
        {
            if (it->second->getNickname() == nickName)
            {
                // 이미 사용 중인 닉네임이라면 언더스코어 추가
                int underscoreCount = 0;
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
        return ;
    }

    else
    {
        for(std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
        {
            if (it->second->getNickname() == nickName) // 같을 경우
            {
                std::string responseMsg = ":ft_irc 433 " + client->getNickname() + " " + nickName + " :Nickname is already in use.";
                sendResponse(responseMsg, client);
                return ;
            }
        }
    }
    std::string responseMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 NICK :" + nickName;
    sendResponse(responseMsg, client);
    client->setNickname(nickName);
}
