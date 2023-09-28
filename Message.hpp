#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <Client.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

struct MessageInfo {
    std::string command;
    std::vector<std::string> params;
};

class Message{
    private:
        MessageInfo msg;        
        bool crlf;
    public:
        Message(std::string msg);
        ~Message();
        //메세지 파싱
        void parseMessage(std::string msg);
        MessageInfo &getMessageInfo();
};

#endif
