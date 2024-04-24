#include <fstream>
#include <iostream>
#include <string>

void replace_line(std::string &line, std::string s1, std::string s2)
{
    std::string::size_type first = 0;
    std::string::size_type last;

    while (1)
    {
        last = line.find(s1, first);
        if (last == std::string::npos)
            return ;
        line.erase(last, s1.length());
        line.insert(last, s2);
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

    std::string newFile(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);
    std::ifstream in;
    std::string content;
    std::string line;

    in.open(av[1]);
    if (!in.is_open())
    {
        std::cout << "file open is failed" << std::endl;
        return (1);
    }


    std::ofstream out;
    newFile.append(".replace");
    out.open(newFile.c_str());

    if (!out.is_open())
    {
        std::cout << "replace file is not created" << std::endl;
        in.close();
        return (1);
    }
    while (!in.eof())
    {
        std::getline(in, line);
        content += line;
        if (!in.eof())
            content += "\n";
    }
    if (!s1.empty())
        replace_line(content, s1, s2);
    out << content;
    in.close();
    out.close();

    return (0);
}
