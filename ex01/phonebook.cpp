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

        void showContact()
        {
            std::cout << "|     index| first name| last name|  nickname|" << std::endl;
            std::cout << "|" << "index" << "|" << this->firstName << "|" << this->lastName << "|" << this->nickName << "|" << std::endl;
        }
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     number = 0;

    public:
        void searchContact()
        {
            contacts[this->number % 8].showContact();
        }

        void addPhonebookContact()
        {
            contacts[this->number % 8].addContact();
            this->number++;
        }

        void showAllContacts()
        {
            int i;

            i = 0;
            while (i < 8)
            {
                contacts[i].showContact();
                i++;
            }
        }
};

int main()
{
    std::string str;
    PhoneBook phoneBook;

    while (1)
    {
        std::cout << "PLEASE ENTER COMMAND: ";
        std::cin >> str;

        if (str == "EXIT")
            break;
        else if (str == "ADD")
        {
            phoneBook.addPhonebookContact();
        }
        else if (str == "SEARCH")
        {
            phoneBook.showAllContacts();            
        }
    }
    return (0);
}
