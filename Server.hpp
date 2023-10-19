#ifndef SERVER_HPP
#define SERVER_HPP

/* irc */
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "Client.hpp"
#include "Channel.hpp"

/* socket */
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/event.h>
#include <fcntl.h>

struct Udata
{
    std::string buf;
};

class Server{
    private:
        unsigned int port;
        std::string password;
        std::map<int, Client*>clients;
        std::map<int, Client*>nClients;
        std::map<std::string, Channel*>channels;
    
    public:
        Server(char *port, char *password);
        ~Server();

        /* action*/
        int runServer();

        /* Client */
        void communicateClient(int fd, std::string buffer);
        void addClientToServer(Client *client);
        void removeClient(Client *client);
        void joinChannel();
        bool isExistClient(std::string nickname);
    
        /* Channel*/
        bool isExistChannel(std::string name);
        void addChannel(std::string name);
        void removeChannel(std::string name);
        void addClientToChannel(std::string name, Client *client, std::string password);
        void removeClientFromChannel(std::string name, Client *client);
        Client *getClient(std::string nickname);
        Channel *getChannel(std::string channelName);
        bool isOperatorClient(std::string channelName, int fd);
        void setChannelMode(std::string channelName, ChannelMode mode, std::string param, Client *client);
        void removeChannelMode(std::string channelName, ChannelMode mode, std::string param, Client *client);
        bool isChannelModeApplied(std::string channelName, ChannelMode mode);
        std::string getChannelModes(std::string channelName);
        void addChannelOperator(std::string channelName, std::string nickname);
        void addChannelInvite(std::string channelName, std::string nickname);

        /* cmds */
        void runCommand(MessageInfo *msg, Client *client);
        void pass(MessageInfo *msg, Client *client);
        void ping(MessageInfo *msg, Client *client);
        void nick(MessageInfo *msg, Client *client);
        void user(MessageInfo *msg, Client *client);
        void join(MessageInfo *msg, Client *client);
        void part(MessageInfo *msg, Client *client);
        void names(MessageInfo *msg, Client *client);
        void topic(MessageInfo *msg, Client *client);
        void list(MessageInfo *msg, Client *client);
        void invite(MessageInfo *msg, Client *client);
        void kick(MessageInfo *msg, Client *client);
        void mode(MessageInfo *msg, Client *client);
        void privmsg(MessageInfo *msg, Client *client);
        void notice(MessageInfo *msg, Client *client);
        void who(MessageInfo *msg, Client *client);
        void quit(MessageInfo *msg, Client *client);
        void whois(MessageInfo *msg, Client *client);
        
        /* utils */
        unsigned int convertPort(char *port);
        void setMessageInfo(std::vector<MessageInfo> &msg, std::string buf);
        bool clientExistsWithNickname(const std::string& nickname);

        /* send */
        void sendMessage(Client *client, std::string cmd);
        void sendMessageAll(Client *client, std::string msg, std::string channelName);
        void sendMessageAllWithOutMe(Client *client, std::string msg, std::string channelName);
        void sendResponse(std::string msg, Client *client);
        void invitingRPL(int fd, std::string nickname, std::string channelName);

        /* error send */
        void noSuchNick(int fd, std::string nickname, std::string params);
        void noSuchChannel(int fd, std::string nickname, std::string params);
        void notEnoughParams(int fd, std::string nickname, std::string params);
        void noPrivileges(int fd, std::string nickname, std::string params);
        void noChannelOperPrivileges(int fd, std::string nickname, std::string channelName);
        void invalidModeParam(Client *client, std::string channelName, std::string modeName);
        void badChannelKey(Client *client, std::string channelName);
        void channelIsFull(Client *client, std::string channelName);
        void inviteOnly(Client *client, std::string channelName);
        void notOnChannel(Client *client, std::string channelName, std::string userName);
        void MeNotOnChannel(Client *client, std::string channelName);
};

#endif
