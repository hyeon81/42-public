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
        std::map<int, Client*>clients;
        std::map<std::string, Channel*>channels;
    
    public:
        Server(char *port, char *password);
        ~Server();

        /* action*/
        int runServer();
        void tmpRunServer();

        /* Client */
        void communicateClient(int fd, std::string buffer);
        void addClient(Client *client);
        void removeClient();
        void joinChannel();
    
        /* Channel*/
        bool isExistChannel(std::string name);
        void addChannel(std::string name);
        void removeChannel(std::string name);
        void addClientToChannel(std::string name, Client *client);
        void removeClientFromChannel(std::string name, Client *client);
        Client *getClient(std::string nickname);
        Channel *getChannel(std::string channelName);
        void sendToChannel(std::string name, std::string msg);
        bool isOperatorClient(std::string channelName, int fd);
        void setChannelMode(std::string channelName, ChannelMode mode, std::string param, char oper);
        void removeChannelMode(std::string channelName, ChannelMode mode, std::string param, char oper);
        bool isChannelModeApplied(std::string channelName, ChannelMode mode);
        std::string getChannelModes(std::string channelName);
        void addChannelOperator(std::string channelName, std::string nickname);
        void addChannelInvite(std::string channelName, std::string nickname);

        /* cmds */
        void runCommand(MessageInfo &msg, Client *client);
        void pass(MessageInfo &msg, Client *client);
        void nick(MessageInfo &msg, Client *client);
        void user(MessageInfo &msg, Client *client);
        void join(MessageInfo &msg, Client *client);
        void part(MessageInfo &msg, Client *client);
        void names(MessageInfo &msg, Client *client);
        void topic(MessageInfo &msg, Client *client);
        void list(MessageInfo &msg, Client *client);
        void invite(MessageInfo &msg, Client *client);
        void kick(MessageInfo &msg, Client *client);
        void mode(MessageInfo &msg, Client *client);
        void privmsg(MessageInfo &msg, Client *client);
        void notice(MessageInfo &msg, Client *client);
        
        /* utils */
        unsigned int convertPort(char *port);
        void sendResponse(std::string msg, Client *client);
        void noSuchNick(int fd, std::string nickname, std::string params);
        void noSuchChannel(int fd, std::string nickname, std::string params);
        void notEnoughParams(int fd, std::string nickname, std::string params);
        void invitingRPL(int fd, std::string nickname, std::string channelName);

        /* debug */
        void showInfo();
};

#endif
