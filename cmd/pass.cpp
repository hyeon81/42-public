#include "../Server.hpp"

//PASS 0801
void Server::pass(MessageInfo &msg, Client *client)
{
    std::cout << "pass" << std::endl;
    //비밀번호가 일치하는지 확인
    if (!msg.params.size())
        return;
    std::string clientPw = msg.params[0]; 
    if (clientPw == this->password)
    {
        std::cout << "valid" << std::endl;
        client->setValid(true);
    }
}
