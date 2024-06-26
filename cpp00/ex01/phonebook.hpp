#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

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

        void getValidLine(std::string str, std::string msg)
        {
            std::string line;

            std::cout << msg;
            std::cin.ignore();
            std::getline(std::cin, line);
            std::cout << line << std::endl;
            // while (line.empty())
            // {
            //     std::cout << "Empty Input!" << std::endl;
            //     std::cout << line << std::endl;
            //     std::cout << msg;
            //     std::cin.ignore();
            //     std::getline(std::cin, line, '\n');
            // }
            str = line;
        }

    public:
        void addContact(int idx)
        {
            getValidLine(this->firstName, "Please Input Firstname: ");
            std::cout << "Please Input Lastname: ";
            std::cin.ignore();
            std::getline(std::cin, this->lastName);
            std::cout << "Please Input Nickname: ";
            std::cin.ignore();
            std::getline(std::cin, this->nickName);
            std::cout << "Please Input Phone number: ";
            std::cin.ignore();
            std::getline(std::cin, this->phoneNumber);
            std::cout << "Please Input Darkest Secret: ";
            std::cin.ignore();
            std::getline(std::cin, this->darkestSecret);
            this->index = idx;
        }

        void shortenContact(std::string str)
        {
            if (str.length() > 10)
            {
                std::cout << str.substr(0, 9);
                std::cout << "." << "|" ;
            }
            else
            {
                std::cout << std::right;
                std::cout << std::setw(10) << str << "|" ;
            }
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
        void addPhonebookContact()
        {
            contacts[this->number % 8].addContact(this->number % 8);
            this->number++;
        }

        void showAllContacts()
        {
            int i = 0;

            if (this->number <= 0)
            {
                std::cout << "No Contact. Please Add Contact." << std::endl;
                return ;
            }
            else if (this->number > 7)
            {
                showLable();
                while (i < 8)
                {
                    contacts[i].showContact();
                    i++;
                }
            }
            else
            {
                showLable();
                while (i < this->number)
                {
                    contacts[i].showContact();
                    i++;
                }
            }
            searchContact();
        }

        void showLable()
        {
            std::cout << std::right;
            std::cout << "|" ;
            std::cout << std::setw(10) << "index" << "|" ;
            std::cout << std::setw(10) << "first name" << "|" ;
            std::cout << std::setw(10) << "last name" << "|" ;
            std::cout << std::setw(10) << "nickname" << "|" ;
            std::cout << std::endl;
        }

        void searchContact()
        {
            while (1)
            {
                std::cout << "Please Select Index: ";
                std::cin >> this->searchIdx;
                if (std::cin.fail())
                {
                    std::cout << "Wrong Index... Please Select Valid Index" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                else if (this->searchIdx >= 0 && this->searchIdx <= 7 && this->number > this->searchIdx)
                {
                    showLable();
                    contacts[this->searchIdx].showContact();
                    break;
                }
                else
                    std::cout << "Wrong Index... Please Select Valid Index" << std::endl;
            }
        }
};

#endif