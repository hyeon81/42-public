#include "Serializer.hpp"

int main()
{
    Data ptr;
    uintptr_t u_ptr;
    Data *ptr2;
    
    ptr.name = "new";
    std::cout << "name: " << ptr.name << std::endl;
    std::cout  << "ptr: " << &ptr << std::endl;

    u_ptr = Serializer::serialize(&ptr);
    std::cout << "u_ptr: " << &u_ptr << std::endl;
    std::cout << "u_ptr value: " << u_ptr << std::endl;

    ptr2 = Serializer::deserialize(u_ptr);

    //값을 바꾸기
    //확인
    std::cout << "name: " << ptr2->name << std::endl;
    std::cout << "ptr2: " << &ptr2 << std::endl;
}