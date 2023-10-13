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

void Server::noPrivileges(int fd, std::string nickname, std::string params)
{
    //481
}

void Server::channelOperatorPrivilegesNeeded(int fd, std::string nickname, std::string channelName)
{
    std::string msg = ":ft_irc 482 " + nickname +  " " + channelName + " :You're not channel operator\r\n";
    send(fd, msg.c_str(), msg.size(), 0);  
}

//:root!root@127.0.0.1 MODE #hello :+i
void Server::sendModeMessage(Client *client, std::string channelName, std::string mode)
{
    //<nick>!<user>@<host>
    std::string msg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 MODE " + channelName + " :" + mode + "\r\n";
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
}

//INVALIDMODEPARAM
// "<client> <target chan/user> <mode char> <parameter> :<description>"
//:irc.local 696 root_ #hello o * :You must specify a parameter for the op mode. Syntax: <nick>
void Server::invalidModeParam(Client *client, std::string channelName, std::string modeName)
{
    std::string msg = ":ft_irc 696 " + client->getNickname() +  " " + channelName + " " + modeName + " : You must specify a parameter for the op mode.\r\n";
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
}