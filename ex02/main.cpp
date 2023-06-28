#include "Base.hpp"

int main()
{
    Base *test = generate();
    Base *test2 = generate();

    identify(test);
    identify(*test);
    identify(test2);
    identify(*test2);
}
