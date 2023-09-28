#include "Client.hpp"

Client::Client(int fd): fd(fd)
{}

Client::~Client()
{}

void Client::setValid()
{
    this->valid = true;
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