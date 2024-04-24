#include <iostream>
#include <Array.hpp>

// #define MAX_VAL 750
#define MAX_VAL 10

int main(int, char**)
{
    {
        const Array<int> numbers(MAX_VAL);
        std::cout << numbers[0] << std::endl;
    }
    //subject test
    Array<int> numbers(MAX_VAL);

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        // const int value = rand();
        const int value = rand() % 10;
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "====numbers====" << std::endl;
    numbers.showArray();

    //SCOPE
    {
        Array<int> tmp = numbers;
        std::cout << "====tmp====" << std::endl;
        tmp.showArray();

        Array<int> test(tmp);
        std::cout << "====test====" << std::endl;
        test.showArray();
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand()%10;
    }
    std::cout << "====numbers====" << std::endl;
    numbers.showArray();

    delete [] mirror;
    return 0;
}
