#include "../Server.hpp"

/*
ERROR :Closing link: (root@127.0.0.1) [Quit: leaving]
*/

void Server::quit(MessageInfo *msg, Client *client)
{
    if (msg)
    {
        std::string responseMsg = "ERROR :CLosing link: (" + client->getUsername() + 
            "@127.0.0.1) [Quit: leaving]";
        sendResponse(responseMsg, client);
        removeClient(client);
    }
}
