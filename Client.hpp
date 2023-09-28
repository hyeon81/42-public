#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>

class Client{
    private:
        int fd;
        bool isValid;
        std::string nickname;
        std::string realname;
        std::string username;
        std::string read_buf;
        std::string send_buf;

    public:
        Client(int fd);
        ~Client();
        void setValid();
        std::string &getReadBuf();
        void setReadBuf(std::stirng buffer);
        void setNickname(std::string nickname);
        
};

#endif
