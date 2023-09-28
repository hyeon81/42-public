#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <iostream>
#include <map>
#include <stdexcept>
#include "Client.hpp"
#include "Message.hpp"
#include "Channel.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/event.h>
#include <vector>
#include <fcntl.h>

struct MessageInfo {
    std::string command;
    std::vector<std::string> params;
};

class Server{
    private:
        unsigned int port;
        std::string password;
        std::map<int, Client>clients;
    
    public:
        Server(std::string port, std::string password);
        ~Server();

        /* action*/
        int runServer();
        void tmpRunServer()
        void communicateClient();
        void addClient(Client &client)
        void removeClient();
        void joinChannel();
    
        /* cmds */
        void runCommand(std::string cmd);
        void pass(Client &client);
        void nick(Client &client);
        void user(Client &client);
        void join(Client &client);
        void part(Client &client);
        void names(Client &client);
        void topic(Client &client);
        void list(Client &client);
        void invite(Client &client);
        void kick(Client &client);
        void mode(Client &client);
        void privmsg(Client &client);
        void notice(Client &client);

        /* utils */
        unsigned int convertPort(std::string port);
};

#endif
