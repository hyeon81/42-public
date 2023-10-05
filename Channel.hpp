#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Client.hpp"

enum ChannelMode {
    INVITE,
    TOPIC,
    KEY,
    OPER,
    LIMIT
};

class Channel{
    private:
        std::string name;
        std::string topic;
        int modes[5];
        //string(realname)으로 할지, int(fd)로 할지 결정해야함
        std::map<int, Client>clients;
        int operatorFd;
        
    public:
        Channel();
        Channel(std::string name);
        ~Channel();
        
        void setOperatorFd(int fd);
        bool isOperator(int fd);
        std::string &getTopic();
        void setTopic(std::string topic);
        std::string &getName();

        /* mode */
        bool isModeApplied(ChannelMode mode);
        void setMode(int mode);
        void removeMode(int mode);

        /* client */
        void addClient(Client &client);
        void removeClient(Client &client);
        void showClients();

        /* debug */
        void showInfo();
};

#endif
