#include "Server.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cerr << "argument is only 3" << std::endl;
        return (0);
    }
    try 
    {
        Server server(av[1], av[2]);
        server.runServer();
    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;     
    }
}