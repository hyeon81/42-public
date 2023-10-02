#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

struct MessageInfo {
    //prefix
    std::string cmd;
    std::string param;
    bool isLast;
    std::vector<std::string> params;
};

class Message{
    private:
        std::vector<MessageInfo> msgInfo;
    public:
        Message();
        ~Message();
        //메세지 파싱
        void setMessageInfo(std::string buf);
        void clearMsgs();
        std::vector<MessageInfo> &getMsgs();
        void showInfo();
};

#endif
