#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    t_complain complains[4];

    complains[0].level = "DEBUG";
    complains[0].func = &Harl::debug;
    complains[1].level = "INFO";
    complains[1].func = &Harl::info;
    complains[2].level = "WARNING";
    complains[2].func = &Harl::warning;
    complains[3].level = "ERROR";
    complains[3].func = &Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if (complains[i].level == level)
        {
            (this->*complains[i].func)();
            break;
        }
    }
}
