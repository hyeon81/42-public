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
        int         index;

    public:
        void addContact(int index)
        {
            std::cout << "Please Input Firstname: ";
            std::cin >> this->firstName;
            std::cout << "Please Input Lastname: ";
            std::cin >> this->lastName;
            std::cout << "Please Input Nickname: ";
            std::cin >> this->nickName;
            std::cout << "Please Input Phone number: ";
            std::cin >> this->phoneNumber;
            std::cout << "Please Input Darkest Secret: ";
            std::cin >> this->darkestSecret;
            this->index = index;
        }

        void shortenContact(std::string str)
        {
            if (str.length() > 10)
            {
                std::cout << str.substr(0, 9);
                std::cout << "." << "|" ;
            }
            else
                std::cout << std::setw(10) << str << "|" ;
        }

        void showContact()
        {
            std::cout << std::right;
            std::cout << "|" ;
            shortenContact(std::to_string(this->index));
            shortenContact(this->firstName);
            shortenContact(this->lastName);
            shortenContact(this->nickName);
            std::cout << std::endl;
        }
        
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     number;
        int     searchIdx;

    public:
        void searchContact()
        {
            while (1)
            {
                std::cout << "Please Select Index: ";
                std::cin >> this->searchIdx;
                if (searchIdx < 0 || searchIdx > 7 || number < searchIdx)
                    std::cout << "Wrong Index... Please Select Valid Index" << std::endl;
                else
                {
                    std::cout << std::right;
                    std::cout << "|" ;
                    contacts[0].shortenContact("index");
                    contacts[0].shortenContact("first name");
                    contacts[0].shortenContact("last name");
                    contacts[0].shortenContact("nickname");
                    std::cout << std::endl;
                    contacts[this->searchIdx].showContact();
                    break;
                }
            }
        }

        void addPhonebookContact()
        {
            contacts[this->number % 8].addContact(this->number % 8);
            this->number++;
        }

        void showAllContacts()
        {
            int i = 0;

            std::cout << std::right;
            std::cout << "|" ;
            contacts[0].shortenContact("index");
            contacts[0].shortenContact("first name");
            contacts[0].shortenContact("last name");
            contacts[0].shortenContact("nickname");
            std::cout << std::endl;

            if (this->number > 7)
            {
                while (i < 8)
                {
                    contacts[i].showContact();
                    i++;
                }
            }
            else
            {
                while (i < this->number)
                {
                    contacts[i].showContact();
                    i++;
                }
            }
            searchContact();
        }
};

int main(void)
{
    std::string str;
    PhoneBook phoneBook;

    while (1)
    {
        std::cout << "Please Input Command(ADD, SEARCH, EXIT): ";
        std::cin >> str;

        if (str == "EXIT" || str == "exit")
            break;
        else if (str == "ADD" || str == "add")
        {
            phoneBook.addPhonebookContact();
        }
        else if (str == "SEARCH" || str == "search")
        {
            phoneBook.showAllContacts();         
        }
        else
        {
            std::cout << "Command Not Found" << std::endl;
        }
    }
    return (0);
}
