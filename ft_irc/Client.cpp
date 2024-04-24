#include "Client.hpp"


Client::Client(int fd): fd(fd) , signonTime(0), idleTime(0)
{
    this->valid = false;
    this->invite = false;
    this->updateSignonTime();
    this->currentChannel = "*";
}

Client::~Client()
{
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

void Client::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

std::string Client::getNickname()
{
    return (this->nickname);
}


std::string &Client::getRealname()
{
    return (this->realname);
}

std::string Client::getCurrentchannel() //
{
    return(currentChannel);
}

void Client::setCurrentchannel(std:: string channelname) //
{
    this -> currentChannel = channelname;
    
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

void Client::updateSignonTime() //Sign-on Time: 최종으로 서버에 접속한 시간
{
    signonTime = std::time(0);
}

void Client::updateIdleTime() //Idle Time: 휴면 시간
{
    time_t currentTime = std::time(0);
    idleTime = currentTime - signonTime;
}

time_t Client::getIdleTime()
{
    return(idleTime);
}

time_t Client::getSignonTime()
{
    return(signonTime);
}
