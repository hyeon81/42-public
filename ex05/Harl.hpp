#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        void complain(std::string level);
};

typedef struct s_complain {
    std::string level;
    void (Harl::*func)(void);
} t_complain;

#endif