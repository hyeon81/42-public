#include "../Server.hpp"


void Server::pass(MessageInfo &msg, Client &client) 
{
    std::string errorMsg;
    if (!msg.params.size()) // pass가 안들어왔을 경우 그냥 리턴 ? or error
    {
        errorMsg = "<client> <command> :Not enough parameters";
        sendResponse(errorMsg, client);
    }
    std::string clientPw = msg.params[0]; // 들어왔다면 첫번째 애를 저장
    if (clientPw == this->password) 
        client.setValid(true); // password의 유무를 판단하기 위해 만든거라 기능을 분리 할 필요가
    else
    {
        errorMsg =  "<client> :Password incorrect" << std::endl;
        sendResponse(errorMsg, client);
    }
}

