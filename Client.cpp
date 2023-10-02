#include "Client.hpp"

Client::Client(int fd): fd(fd)
{
    std::cout << "Client constructor" << std::endl;
    this->valid = false;
}

Client::~Client()
{
    std::cout << "Client destructor" << std::endl;
}

int &Client::getSocket()
{
    return (this->fd);
}

void Client::setValid()
{
    this->valid = true;
}

bool Client::getValid()
{
    return (this->valid);
}

std::string& Client::getReadBuf()
{
    return (this->read_buf);
}

void Client::setReadBuf(std::stirng buffer)
{
    this->read_buf = buffer;
}

void Client::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void Client::setUsername(std::string username, std::string realname)
{
    this->username = username;
    this->realname = realname;
}
