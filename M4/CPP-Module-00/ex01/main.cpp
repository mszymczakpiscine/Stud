/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:40:23 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/30 21:40:23 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>


int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }

        if (command == "ADD")
        {
            Contact newContact;
            std::string input;

            std::cout << "First Name: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.set_first_name(input);

            std::cout << "Last Name: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.set_last_name(input);

            std::cout << "Nickname: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.set_nickname(input);

            std::cout << "Phone Number: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.set_phone_number(input);

            std::cout << "Darkest Secret: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                break;
            newContact.set_darkest_secret(input);

            if (newContact.is_valid())
                phoneBook.add_contact(newContact);
            else
                std::cout << "All fields are required. Contact not added." << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.search_contacts();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else if (!command.empty())
        {
            std::cout << "Unknown command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}