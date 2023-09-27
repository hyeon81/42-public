#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <iostream>

class Server{
    private:
        unsigned int port;
        std::string password;
    public:
        Server(unsigned int port, std::string password);
        ~Server();
        
};

#endif
