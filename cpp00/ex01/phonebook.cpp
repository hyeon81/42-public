#include "phonebook.hpp"

int main(void)
{
    std::string str;
    PhoneBook phoneBook;

    while (1)
    {
        std::cout << "Please Input Command(ADD, SEARCH, EXIT): ";
        getline(std::cin, str);

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
        else
        {
            std::cout << "Command Not Found" << std::endl;
        }
    }
    return (0);
}
