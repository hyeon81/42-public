#include <iosteam>
#include <string>
#include "Server.hpp"

int main(int ac, char **av)
{
    unsigned int port;
    std::string password;
    // av[1] = port
    // av[2] = password
    // ac 가 3개 이상이면 오류?
    if (ac != 3)
    {
        std::cout << "argument is only 3" << std::endl;
        return (0);
    }

    //일단 다 숫자인지 확인
    for (unsigned int i = 0; i < )
    {
        
    }
    port = strtod(av[1], &stopstring);

    //서버 생성
    Server server(port, password);
    //비밀번호와 포트번호 검증
    
    //서버 while 클라이언트 생성, 생성 후 메세지 받아서 파싱, 실행, 출력
}