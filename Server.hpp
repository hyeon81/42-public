#ifndef SERVER_HPP
#define SERVER_HPP

/* irc */
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include "Client.hpp"
#include "Message.hpp"
#include "Channel.hpp"

/* socket */
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/event.h>
#include <fcntl.h>

class Server{
    private:
        unsigned int port;
        std::string password;
        std::map<int, Client>clients;
        std::map<std::string, Channel>channels;
    
    public:
        Server(char *port, char *password);
        ~Server();

        /* action*/
        int runServer();
        void tmpRunServer();

        /* Client */
        void communicateClient(Client &client);
        void addClient(Client &client);
        void removeClient();
        void joinChannel();
    
        /* Channel*/
        bool isExistChannel(std::string name);
        void addChannel(std::string name);
        void removeChannel(std::string name);
        void addClientToChannel(std::string name, Client &client);
        void removeClientFromChannel(std::string name, Client &client);
        Client &getClientWithNickname(std::string nickname);
        void sendToChannel(std::string name, std::string msg);
        bool isOperatorClient(std::string channelName, int fd);
        void setChannelMode(std::string channelName, std::string mode);

        /* cmds */
        void runCommand(MessageInfo &msg, Client &client);
        void pass(MessageInfo &msg, Client &client);
        void nick(MessageInfo &msg, Client &client);
        void user(MessageInfo &msg, Client &client);
        void join(MessageInfo &msg, Client &client);
        void part(MessageInfo &msg, Client &client);
        void names(MessageInfo &msg, Client &client);
        void topic(MessageInfo &msg, Client &client);
        void list(MessageInfo &msg, Client &client);
        void invite(MessageInfo &msg, Client &client);
        void kick(MessageInfo &msg, Client &client);
        void mode(MessageInfo &msg, Client &client);
        void privmsg(MessageInfo &msg, Client &client);
        void notice(MessageInfo &msg, Client &client);

        /* utils */
        unsigned int convertPort(char *port);
        void sendResponse(std::string msg, Client& client);

        /* debug */
        void showInfo();
};

#endif
