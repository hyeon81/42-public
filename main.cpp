#include <iosteam>
#include <string>
#include "Server.hpp"

int main(int ac, char **av)
{
    // av[1] = port
    // av[2] = password
    // ac 가 3개 이상이면 오류?
    if (ac != 3)
    {
        //std::cerr
        std::cout << "argument is only 3" << std::endl;
        return (0);
    }
    try 
    {
        //서버 생성
        Server server(av[1], av[2]);
        //서버 실행
        server.runServer();
    } catch (std::exception &e)
    {
        std::cerr << "exception occurs: " << e.what() << std::endl;     
    }
    
    //서버 while 클라이언트 생성, 생성 후 메세지 받아서 파싱, 실행, 출력
}