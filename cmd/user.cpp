#include "../Server.hpp"

//USER root root 127.0.0.1 :root
//<username> <hostname> <servername> <realname>
//1번째랑 4번째만 사용
void Server::user(MessageInfo &msg, Client &client)
{
    std::cout << "===user====" << std::endl;
    //유저일때는 parmas 없어도 응답 보냄.
    if (!msg.params.size())
    {
        //오류 메세지 보내기
    }
    std::string username = msg.params[0];
    std::string realname;
    if (msg.params.size() > 3)
        realname = msg.params[3];
    //인자가 덜 들어왔을때 처리 확인 필요
    //username, realname이 겹칠 경우 조치 필요
    client.setUsername(username, realname);
    // //유저가 들어왔을때 client 등록한다고 판단. pass와 nick이 먼저 들어와야함.
    client.setValid(true);
    addClient(client);
    sendResponse(":ft_irc 001 hyeokim2 :Welcome to the <networkname> Network, <nick>[!<user>@<host>]", client);
}