#include "../Server.hpp"

//TOPIC #test //채널 토픽보여줌
//TOPIC #test :New topic //채널 토픽 변경
void Server::topic(MessageInfo &msg, Client &client)
{
    if (isExistChannel(msg.params[0]))
    {
        //토픽이 없으면 보여줌
        if (msg.params.size() == 0)
        {
            std::cout << channels[msg.params[0]].getTopic() << std::endl;
        }
        //토픽이 있으면 변경
        else
        {
            std::string topic = msg.params[1];
            channels[msg.params[0]].setTopic(topic);
        }
    }
}