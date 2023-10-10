#include "Server.hpp"

void Server::sendResponse(std::string msg, Client *client)
{
    msg.append("\r\n");
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
}

void Server::noSuchNick(int fd, std::string nickname, std::string params)
{
    std::string msg = ":ft_irc 401 " + nickname + " " + params + " :No such nick/channel";
    send(fd, msg.c_str(), msg.size(), 0);
}

void Server::noSuchChannel(int fd, std::string channelName, std::string params)
{
    std::string msg = ":ft_irc 403 " + channelName + " " + params + " :No such channel";
    send(fd, msg.c_str(), msg.size(), 0);
}

