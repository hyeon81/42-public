#include "Base.hpp"

Base::~Base()
{
    std::cout << "[Base] is destroyed" << std::endl;
}

Base *generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
        return (dynamic_cast<Base*>(new A()));
    else if (random == 1)
        return (dynamic_cast<Base*>(new B()));
    else
        return (dynamic_cast<Base*>(new C()));
}

void identify(Base* p)
{
    std::cout << "[identify *] ";
    if (dynamic_cast<A*>(p))
        std::cout << "p: A";
    else if (dynamic_cast<B*>(p))
        std::cout << "p: B";
    else if(dynamic_cast<C*>(p))
        std::cout << "p: C";
    std::cout << std::endl;
}

void identify(Base& p)
{
    std::cout << "[identify &] ";
    try {
        (void)dynamic_cast<A&>(p); 
        std::cout << "p: A" << std::endl;
    } catch (std::exception &e){ };
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "p: B" << std::endl;
    } catch (std::exception &e){ };
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "p: C" << std::endl;
    } catch (std::exception &e){ };
}
