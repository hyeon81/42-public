#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <Client.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

struct MessageInfo {
    std::string cmd;
    std::string param;
    bool isLast;
    std::vector<std::string> params;
};

class Message{
    private:
        std::vector<MessageInfo> msgs;
    public:
        Message();
        ~Message();
        //메세지 파싱
        void setMsgs(std::string buf);
        void clearMsgs();
        std::vector<MessageInfo> &getMsgs();
};

#endif
