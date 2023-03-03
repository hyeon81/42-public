#include <iostream>
#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
        int     idx;
    
    public:
        Contact()
        {
            std::cout << "PLEASE INPUT FIRSTNAME: ";
            std::cin >> firstName;
            std::cout << "PLEASE INPUT LASTNAME: ";
            std::cin >> lastName;
            std::cout << "PLEASE INPUT NICKNAME: ";
            std::cin >> nickName;
            std::cout << "PLEASE INPUT PHONENUMBER: ";
            std::cin >> phoneNumber;
            std::cout << "PLEASE INPUT DARKEST SECRET: ";
            std::cin >> darkestSecret;
        }

        ~Contact()
        {
        }
};

class PhoneBook {
    Contact contacts[8];
};

int main()
{
    std::string str;

    while (1)
    {
        std::cout << "PLEASE ENTER COMMAND: ";
        std::cin >> str;

        if (str == "EXIT")
            break;
        else if (str == "ADD")
        {
            
        }
        else if (str == "SEARCH")
        {
            
        }
    }
    return (0);
}
