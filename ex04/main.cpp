#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char *av)
{
    if (ac != 4)
        return (1);
    std::ifstream in(av[1]);
    std::string copy;

    if (in.is_open())
    {
        in >> copy;
        std::cout << "입력 받은 문자열 ::" << copy << std::endl;
    } else {
        std::cout << "잘못된 파일입니다" << std::endl;
        return (1);
    }
    
    int i = 0;
    while (copy[i])
    {
        
    }

    in.close();
    std::string newFile = av[1] + ".replace";
    std::ofstream out(newFile);
    newFile << "";
    newFile.close();
}