#include "../Server.hpp"

void Server::pass(MessageInfo *msg, Client *client) 
{
    std::string errorMsg;
    if (!msg->params.size())
    {
        notEnoughParams(client->getSocket(), client->getNickname(), msg->cmd);
        removeClient(client);
        throw std::runtime_error("Not enough parameters"); //return 느낌...?

    }
    std::string clientPw = msg->params[0]; // 들어왔다면 첫번째 애를 저장
    if (clientPw == this->password)
    {
        client->setValid(true);
        return ;
    }
    else // 들어가지면 안돼 왜 생성이 돼 근데 어차피 pass가... 
    {
        errorMsg = ":ft_irc 464 :Password incorrect";
        sendResponse(errorMsg, client);
        // removeClient(client); //이게 아니라 nclient에 등록을 해ㄴ야할듯/ nclient = 소켓 중복 방지
        // client = nClients;
        int clientSocket = client->getSocket();
        if (nClients.find(clientSocket) != nClients.end()) 
        {
            nClients.erase(clientSocket);
            delete client; // 삭제된 클라이언트 객체를 해제
            close(clientSocket); // 클라이언트 소켓 닫기
            throw std::runtime_error("password incorrect");
        }
    }
}

//client가 연결을 끊고 다시 들어갔을때 아무반응을 안한다...
//whois operator에서 터짐 존재하지 않는데 찾으려다 터지는듯...
//who 띄어쓰기 
//user하나가 quit을 하면 우리 서버가 멈춘다