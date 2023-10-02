#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>
#include <Message.hpp>

class Client{
    private:
        int fd;
        Message msg;
        bool isValid;
        std::string nickname;
        std::string realname;
        std::string username;
        std::string read_buf;
        std::string send_buf;

    public:
        Client(int fd);
        ~Client();
        int getSocket();
        void setValid();
        bool getValid();
        std::string &getReadBuf();
        void setReadBuf(std::stirng buffer);
        void setNickname(std::string nickname);      
        void setUsername(std::string username, std::string realname); 
};

#endif
