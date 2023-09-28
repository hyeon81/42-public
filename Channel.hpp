#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Client.hpp"

class Channel{
    private:
        std::string topic;
        int mode;
        std::vector<Client> clients;
        std::string operName; //realname. 이건 변동안되나?
        
    public:
        Channel();
        ~Channel();
};

#endif
