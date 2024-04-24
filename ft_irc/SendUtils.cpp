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
    std::cout << "***send: " << msg << std::endl;
    send(fd, msg.c_str(), msg.size(), 0);
    throw std::runtime_error("no such user");
}

void Server::noSuchChannel(int fd, std::string channelName, std::string params)
{
    std::string msg = ":ft_irc 403 " + channelName + " " + params + " :No such channel\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(fd, msg.c_str(), msg.size(), 0);
    throw std::runtime_error("no such channel");
}

void Server::notEnoughParams(int fd, std::string nickname, std::string params)
{
    std::string msg = ":ft_irc 461 " + nickname + " " + params + " :Not enough parameters\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(fd, msg.c_str(), msg.size(), 0);
    throw std::runtime_error("not enough params");
}

//"341 <client> <nick> <channel>"
void Server::invitingRPL(int fd, std::string nickname, std::string channelName)
{
    std::string msg = ":ft_irc 341 " + nickname + " " + channelName + " :Inviting to channel\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(fd, msg.c_str(), msg.size(), 0);
}

void Server::noChannelOperPrivileges(int fd, std::string nickname, std::string channelName)
{
    std::string msg = ":ft_irc 482 " + nickname +  " " + channelName + " :You're not channel operator\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(fd, msg.c_str(), msg.size(), 0);
    throw std::runtime_error("not channel operator");
}

//:irc.local 475 root_ #hello :Cannot join channel (incorrect channel key)
void Server::badChannelKey(Client *client, std::string channelName)
{
    if (!client)
        return ;

    std::string msg = ":ft_irc 475 " + client->getNickname() + " " + channelName + " :Cannot join channel (incorrect channel key)\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);  
    throw std::runtime_error("bad channel key");
}

//:irc.local 473 root_ #hello :Cannot join channel (invite only)
void Server::inviteOnly(Client *client, std::string channelName)
{
    if (!client)
        return ;

    std::string msg = ":ft_irc 473 " + client->getNickname() + " " + channelName + " :Cannot join channel (invite only)\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0); 
    throw std::runtime_error("invite only"); 
}

void Server::channelIsFull(Client *client, std::string channelName)
{
    if (!client)
        return ;

    std::string msg = ":ft_irc 471 " + client->getNickname() +  " "  + channelName + " :Cannot join channel (channel is full)\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);  
    throw std::runtime_error("channel is full");
}

//:irc.local 696 root_ #hello o * :You must specify a parameter for the op mode. Syntax: <nick>
void Server::invalidModeParam(Client *client, std::string channelName, std::string modeName)
{
    if (!client)
        return ;

    std::string msg = ":ft_irc 696 " + client->getNickname() +  " " + channelName + " " + modeName + " : You must specify a parameter for the op mode.\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
    throw std::runtime_error("invalid mode param");
}

//:root!root@127.0.0.1 KICK #hello root :sdjfjklsdflfds
void Server::sendMessage(Client *client, std::string cmd)
{
    if (!client)
        return ;

    //<nick>!<user>@<host>
    std::string msg = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + cmd + "\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
}

//:root_!root@127.0.0.1 TOPIC #hello :124
void Server::sendMessageAll(Client *client, std::string msg, std::string channelName)
{
    std::vector<Client*> members = channels[channelName]->getChannelMembers();
    std::string m = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + msg + "\r\n";
    
    if (!client)
        return ;

    for (size_t i = 0; i < members.size(); i++) 
    {
        std::cout << "***send: " << members[i]->getSocket() << "m: " << m << std::endl;
        send(members[i]->getSocket(), m.c_str(), m.size(), 0);
    }
}

void Server::sendMessageAllWithOutMe(Client *client, std::string msg, std::string channelName)
{
    std::vector<Client*> members = channels[channelName]->getChannelMembers();
    std::string m = ":" + client->getNickname() + "!" + client->getUsername() + "@127.0.0.1 " + msg + "\r\n";
    
    for (size_t i = 0; i < members.size(); i++) 
    {
        if (members[i]->getSocket() != client->getSocket())
        {
            std::cout << "***send: " << m << std::endl;
            send(members[i]->getSocket(), m.c_str(), m.size(), 0);
        }
    }
}

//irc.local 441 root_ root #hello :They are not on that channel
void Server::notOnChannel(Client *client, std::string channelName, std::string userName)
{
    if (!client)
        return ;

    std::string msg = ":ft_irc 441 " + client->getNickname() + " " + userName + " " + channelName + " :They are not on that channel\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
    throw std::runtime_error("not on channel");
}

bool Server::clientExistsWithNickname(const std::string& nickname)
{
    for (std::map<int, Client*>::const_iterator it = clients.begin(); it != clients.end(); ++it) {
        if (it->second->getNickname() == nickname) {
            return true; // 같은 닉네임의 클라이언트가 이미 존재함
        }
    }
    return false; // 같은 닉네임의 클라이언트가 존재하지 않음
}

void Server::MeNotOnChannel(Client *client, std::string channelName)
{
    if (!client)
        return ;
    
    std::string msg = ":ft_irc 442 " + client->getNickname() + " " + channelName + " :You're not on that channel\r\n";
    std::cout << "***send: " << msg << std::endl;
    send(client->getSocket(), msg.c_str(), msg.size(), 0);
    throw std::runtime_error("not on channel");
}

