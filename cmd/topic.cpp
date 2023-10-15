#include "../Server.hpp"

//TOPIC #test //채널 토픽보여줌
//TOPIC #test :New topic //채널 토픽 변경
void Server::topic(MessageInfo &msg, Client *client, Channel *channel)
{
    if(msg.params.size() == 0)
    {
        //"<client> <command> :Not enough parameters"
        // or  std::cout << channels[msg.params[0]]->getTopic() << std::endl;
    }
    std::string channelName = msg.params[0];
    if (isExistChannel(channelName)) // 존재한다면..?
    {
        if (msg.params.size() < 2) 
        {
            // 주제를 확인하는 경우
            std::string topic = channel->getTopic(); 
            std::string msg = channelName + " " + topic;
            sendResponse(msg, client);
        }
        else 
        {
            //설정
            std::string newTopic = msg.params[1];
            //권한 확인
            if (channel.isModeApplied(TOPIC))
            {
                //:irc.local 482 root #hello :You do not have access to change the topic on this channel
                if (!channel->isOperator(client->getSocket()))
                    channelOperatorPrivilegesNeeded(client->getSocket(), client->getNickname(), channelName);
            }
            channel->setTopic(newTopic);
            std::string msg = "TOPIC " + channelName + " :" newTopic;
            // :root_!root@127.0.0.1 TOPIC #hello :124
            // :root_!root@127.0.0.1 TOPIC #hello :124
            //모든 유저들에게 알림
            sendMessageAll(client, msg);
        }
    }
    else 
    {
        std::string msg = "<client> <channel> :No such channel";
        sendResponse(msg, client);
    }
    
}
