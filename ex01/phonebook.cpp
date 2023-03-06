#include <iostream>
#include <string>
#include <iomanip> 

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

        void showContact(int index)
        {
            std::cout << "|     index| first name| last name|  nickname|" << std::endl;
            std::cout << "|" << index << std::setw(10) << "|"  << this->firstName << std::setw(10) << "|" << this->lastName << std::setw(10) << "|" << this->nickName << std::setw(10) << "|" << std::endl;
        }
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     number;

    public:
        void searchContact()
        {
            contacts[this->number % 8].showContact(this->number % 8);
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
            if (this->number > 7)
            {
                // printf("here");
                while (i < 8)
                {
                    contacts[i].showContact(i);
                    i++;
                }
            }
            else
            {
                // printf("here2");
                while (i < this->number)
                {
                    contacts[i].showContact(i);
                    i++;
                }
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
