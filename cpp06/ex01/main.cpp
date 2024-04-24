#include "Serializer.hpp"

int main()
{
    Data ptr;
    uintptr_t u_ptr;
    Data *ptr2;
    uintptr_t u_ptr2;
    Data *ptr3;
    
    ptr.name = "new";
    std::cout << "ptr_name: " << ptr.name << std::endl;

    u_ptr = Serializer::serialize(&ptr);
    ptr2 = Serializer::deserialize(u_ptr);
    std::cout << "ptr2_name: " << ptr2->name << std::endl;

    ptr2->name = "change";
    u_ptr2 = Serializer::serialize(ptr2);
    ptr3 = Serializer::deserialize(u_ptr2);
    std::cout << "ptr3_name: " << ptr3->name << std::endl;
    
}