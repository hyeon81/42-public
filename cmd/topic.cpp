#include "../Server.hpp"

//TOPIC #test //채널 토픽보여줌
//TOPIC #test :New topic //채널 토픽 변경
void Server::topic(MessageInfo *msg, Client *client)
{
    if(msg->params.size() == 0)
    {
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
        //"<client> <command> :Not enough parameters"
        // or  std::cout << channels[msg->params[0]]->getTopic() << std::endl;
    }
    std::string channelName = msg->params[0];
    if (isExistChannel(channelName)) // 존재한다면..?
    {
        Channel *channel = getChannel(channelName);
        if (!(channel->isMember(client)))
            MeNotOnChannel(client, channelName, client->getNickname());
        if (msg->params.size() < 2) 
        {
            // 주제를 확인하는 경우
            std::string topic = channel->getTopic(); 
            std::string sendMsg = "TOPIC " + channelName + " :" + topic;
            sendMessage(client, sendMsg );
        }
        else 
        {
            //설정
            //권한 확인
            if (channel->isModeApplied(TOPIC))
            {
                //:irc.local 482 root #hello :You do not have access to change the topic on this channel
                if (!channel->isOperator(client->getSocket()))
                    noChannelOperPrivileges(client->getSocket(), client->getNickname(), channelName);
            }
            std::string newTopic = msg->params[1];
            newTopic.erase(0, 1);
            channel->setTopic(newTopic);
            std::string sendMsg  = "TOPIC " + channelName + " :" + msg->params[1];
            // :root_!root@127.0.0.1 TOPIC #hello :124
            //모든 유저들에게 알림
            sendMessageAll(client, sendMsg , channelName);
        }
    }
    else 
        noSuchChannel(client->getSocket(), client->getNickname(), channelName);
}
