#include <iostream>
#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    
    public:
        void addContact()
        {
            std::cout << "PLEASE INPUT FIRSTNAME: ";
            std::cin >> this->firstName;
            std::cout << "PLEASE INPUT LASTNAME: ";
            std::cin >> this->lastName;
            std::cout << "PLEASE INPUT NICKNAME: ";
            std::cin >> this->nickName;
            std::cout << "PLEASE INPUT PHONENUMBER: ";
            std::cin >> this->phoneNumber;
            std::cout << "PLEASE INPUT DARKEST SECRET: ";
            std::cin >> this->darkestSecret;
        }
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;

    public:
        void showContact()
        {
            std::cout << "|" << this->index << "|" << this->firstName << "|" << this->lastName << "|" << this->nickName << "|" << std::endl;
        }
        
        void showAllContacts()
        {
            std::cout << "|     index| first name| last name|  nickname|" << std::endl;
        }  

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
