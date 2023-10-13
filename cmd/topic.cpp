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
    if (isExistChannel(msg.params[0])) // 존재한다면..?
    {
        std::string channelName = msg.params[0];
        if (msg.params.size() < 2) 
        {
            // 주제를 확인하는 경우
            std::string topic = channel->getTopic(); 
            std::string msg = channelName + topic;
            sendResponse(msg, client);
        }
        else 
        {
            //설정
            std::string newTopic = msg.params[1];
            channel->setTopic(newTopic);
            std::string msg = channelName + newTopic;
            sendResponse(msg, client);
        }
    }
    else 
    {
        std::string msg = "<client> <channel> :No such channel";
        sendResponse(msg, client);
    }
    
}


