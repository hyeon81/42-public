#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Client.hpp"

class Channel{
    private:
        std::string name;
        std::string topic;
        int mode;
        //string(realname)으로 할지, int(fd)로 할지 결정해야함
        std::map<int, Client>clients;
        int operatorFd;
        
    public:
        Channel();
        ~Channel();
        void setOperatorFd(int fd);
        bool isOperator(int fd);
        void addClient(Client &client);
        void removeClient(Client &client);
};

#endif
