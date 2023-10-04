#include "Message.hpp"

Message::Message()
{
    std::cout << "Message constructor" << std::endl;
}

Message::~Message()
{
    std::cout << "Message destructor" << std::endl;
}

void Message::setMessageInfo(std::string buf)
{
    std::string delimiter = "\r\n";
    size_t pos = 0;
    std::string rawMsgs;

    while ((pos = buf.find(delimiter)) != std::string::npos) {
        rawMsgs = buf.substr(0, pos);
        buf.erase(0, pos + delimiter.length());

        std::cout << "rawMsgs: " << rawMsgs << std::endl;
        // rawMsgs 파싱하기 (한줄씩)
        std::stringstream mss(rawMsgs);
        MessageInfo msgInfo;
        std::string cmd, param;
        mss >> cmd;
        msgInfo.cmd = cmd;
        while (mss >> param) {
            msgInfo.params.push_back(param);
        }
        // if (msgInfo.params.size() > 1)
        //     msgInfo.param = msgInfo.params[0];
        //이렇게하면 하나의 MessageInfo가 생성됨
        this->msgInfo.push_back(msgInfo);
    }
    //추후에 clrf로 안 끝난 문자열도 처리고려해야 (꼭 안해도 될듯?)
}

void Message::clearMsgs()
{
    //msgInfo안의 messageinfo는 어떻게 없앨필요없나?
    this->msgInfo.clear();
}

std::vector<MessageInfo> &Message::getMsgs()
{
    return (msgInfo);
}
