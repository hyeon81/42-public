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
        std::map<int, Client*>clients;
        std::map<int, Client*>oClients;
        std::map<int, Client*>iClients;
        std::string key;
        unsigned int limit;
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
        void setKey(std::string key);
        void removeKey(std::string key);
        void setLimit(unsigned int limit);
        void removeLimit(unsigned int limit);

        /* client */
        void addClient(Client *client);
        void removeClient(Client *client);
        void showClients();
        void addOperator(Client *client);
        void addInvite(Client *client);
        void removeOperator(Client *client);
        void removeInvite(Client *client);

        /* debug */
        void showInfo();
};

#endif
