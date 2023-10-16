#include "Client.hpp"

Client::Client(int fd): fd(fd)
{
    std::cout << "Client constructor" << std::endl;
    msgs = new Message();
    this->valid = false;
}

Client::~Client()
{
    std::cout << "Client destructor" << std::endl;
}

int Client::getSocket()
{
    return (this->fd);
}

void Client::setValid(bool value)
{
    this->valid = value;
}

bool Client::getValid()
{
    return (this->valid);
}

std::string& Client::getReadBuf()
{
    return (this->read_buf);
}

void Client::setReadBuf(std::string buffer)
{
    this->read_buf = buffer;
}

void Client::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void Client::setMsgs(std::string buf)
{
    //client 내부의 msgs의 메세지 설정
    msgs->setMessageInfo(buf);
}

std::vector<MessageInfo> &Client::getMsgs()
{
    return (msgs->getMsgs());
}

std::string &Client::getNickname()
{
    return (this->nickname);
}

void Client::setUsername(std::string username, std::string realname)
{
    this->username = username;
    this->realname = realname;
}

std::string &Client::getUsername()
{
    return(this->username);
}


void Client::showInfo()
{
    std::cout << "===Client Info====" << std::endl;
    std::cout << "fd: " << this->fd << std::endl;
    std::cout << "nickname: " << this->nickname << std::endl;
    std::cout << "username: " << this->username << std::endl;
    std::cout << "realname: " << this->realname << std::endl;
    std::cout << "read_buf: " << this->read_buf << std::endl;
    std::cout << "send_buf: " << this->send_buf << std::endl;
    std::cout << "valid: " << this->valid << std::endl;
}

bool Client::getInvite()
{
    return (this->invite);
}

void Client::setInvite(bool value)
{
    this->invite = value;
}
