#include "Message.hpp"

Message::Message()
{}

Message::~Message()
{}

void Message::parseBufToMsgs(std::string buf)
{
    std::stringstream ss(buf);
    std::string rawMsgs;
    char delimiter = "\r\n";

    while (std::getline(ss, rawMsgs, delimiter))
    {
        // rawMsgs 파싱하기 (한줄씩)
        std::stringstream mss(rawMsgs);
        MessageInfo msg;

        std::string cmd, param;
        mss >> cmd;
        msg.cmd = cmd;
        while (mss >> param) {
            msg.params.push_back(param);
        }
        if (msg.params.size() > 1)
            msg.param = msg.params[0];
        //이렇게하면 하나의 MessageInfo가 생성됨
        this->msgs.push_back(msg);
    }
    //추후에 clrf로 안 끝난 문자열도 처리고려해야 (꼭 안해도 될듯?)
}

void Message::setMsgs(std::string buf)
{
    this->parseBufToMsgs(buf);
}

void Message::clearMsgs()
{
    //messageinfo는 어떻게 없앨필요없나?
    this->msgs.clear();
}

std::vector<MessageInfo> &Message::getMsgs()
{
    return (msgs);
}
