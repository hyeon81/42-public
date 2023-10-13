#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>
#include "Message.hpp"

class Message;

class Client{
    private:
        int fd;
        Message *msgs;
        bool valid;
        std::string nickname;
        std::string realname;
        std::string username;
        std::string read_buf;
        std::string send_buf;

    public:
        Client(int fd);
        ~Client();
        int getSocket();
        void setValid(bool value);
        bool getValid();
        std::string &getReadBuf();
        void setReadBuf(std::string buffer);
        void setMsgs(std::string buf);
        std::vector<MessageInfo> &getMsgs();
        void setNickname(std::string nickname);      
        std::string &getNickname();
        void setUsername(std::string username, std::string realname);
        std::string &getUsername();
        
        /* debug */
        void showInfo();
};

#endif
