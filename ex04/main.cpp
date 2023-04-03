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

    std::string filename(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);
    std::ifstream in(filename);
    std::string line;

    if (!in.is_open())
    {
        std::cout << "file open is failed" << std::endl;
        return (1);
    }

    std::ofstream newFile(filename.append(".replace"));
    if (!newFile.is_open())
    {
        std::cout << "replace file is not created" << std::endl;
        in.close();
        return (1);
    }
    while (!in.eof())
    {
        std::getline(in, line);
        if (!s1.empty() && !s2.empty())
            replace_line(line, s1, s2);
        newFile << line;
        if (!in.eof())
            newFile << std::endl;
    }
    in.close();
    newFile.close();

    return (0);
}
