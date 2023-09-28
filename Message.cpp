#include "Message.hpp"

Message::Message(std::string msg): msg(msg)
{
    //비어있는 메세지일 경우는?
    parseMessage(msg);
}

Message::~Message()
{}

void Message::parseMessage(std::string msg)
{
    std::stringstream ss(msg);

    //원하는 개수가 아닐 경우 처리 필요
    //일단 변수에 담아주기
    std::string command, param
    ss >> command;
    msg->command = command;

    while (ss >> param) {
        if ((param.size() == 2) && (param[0] == '\r') && (param[1] '\n'))
            break;
        msg->params.push_back(param);
    }
    // this->crlf = crlf;
    //crlf는 어케 처리하지
}

MessageInfo &Message::getMessageInfo()
{
    return (msg);
}
