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
        ChannelMode modes[5];
        std::map<int, Client*>clients;
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
        void setMode(ChannelMode mode);
        void removeMode(ChannelMode mode);
        ChannelMode* getModes();

        /* client */
        void addClient(Client *client);
        void removeClient(Client *client);
        void showClients();

        /* debug */
        void showInfo();
};

#endif
