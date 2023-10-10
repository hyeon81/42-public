#include "Server.hpp"

void Server::sendResponse(std::string msg, Client *client)
{
    msg.append("\r\n");
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
}

void Server::noSuchNick(int fd, std::string nickname, std::string params)
{
    std::string msg = ":ft_irc 401 " + nickname + " " + params + " :No such nick/channel\r\n";
    send(fd, msg.c_str(), msg.size(), 0);
}

void Server::noSuchChannel(int fd, std::string channelName, std::string params)
{
    std::string msg = ":ft_irc 403 " + channelName + " " + params + " :No such channel\r\n";
    send(fd, msg.c_str(), msg.size(), 0);
}

void Server::notEnoughParams(int fd, std::string nickname, std::string params)
{
    std::string msg = ":ft_irc 461 " + nickname + " " + params + " :Not enough parameters\r\n";
    send(fd, msg.c_str(), msg.size(), 0);
}

//"341 <client> <nick> <channel>"
void Server::invitingRPL(int fd, std::string nickname, std::string channelName)
{
    std::string msg = ":ft_irc 341 " + nickname + " " + channelName + " :Inviting to channel\r\n";
    send(fd, msg.c_str(), msg.size(), 0);
}
