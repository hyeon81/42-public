#include <fstream>
#include <iostream>
#include <string>

void replace_line(std::string &line, std::string s1, std::string s2)
{
    std::string::size_type first = 0;
    std::string::size_type last;

    while (1)
    {
        if (s1.empty() || s2.empty())
        {
            std::cout << "s1 or s2 is empty. there is no change" << std::endl;
            return ;
        }
        last = line.find(s1, first); //여기서 first는 찾을 범위의 시작점. last는 찾은 경우의 값
        if (last == std::string::npos) //만약에 이제 다찾아서 끝을 만나면?
        {
            if (first == 0)
                std::cout << "file doesn't include s1. there is no change" << std::endl;
            return ;
        }
        line.erase(last, s1.length());
        line.insert(first, s2);
        std::cout << "content 내용:: " << content << std::endl;
        first = last + s2.length();
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "argument must be 3" << std::endl;
        return (1);
    }

    std::string filename(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);
    std::ifstream in(filename);
    std::string line;
    std::string content;

    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << "입력 받은 문자열 ::" << line << std::endl;
            content << replace_line(line, s1, s2) << std::endl;
        }
    } else {
        std::cout << "file open is failed" << std::endl;
        return (1);
    }
    in.close();
    std::ofstream newFile(filename.append(".replace"));
    if (newFile.is_open())
    {
        newFile << content;
        newFile.close();
    }
}
