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

        if (command == "ADD")
        {
            Contact newContact;
            std::string input;

            std::cout << "First Name: ";
            std::getline(std::cin, input);
            newContact.set_first_name(input);

            std::cout << "Last Name: ";
            std::getline(std::cin, input);
            newContact.set_last_name(input);

            std::cout << "Nickname: ";
            std::getline(std::cin, input);
            newContact.set_nickname(input);

            std::cout << "Phone Number: ";
            std::getline(std::cin, input);
            newContact.set_phone_number(input);

            std::cout << "Darkest Secret: ";
            std::getline(std::cin, input);
            newContact.set_darkest_secret(input);

            if (newContact.is_valid())
                phoneBook.add_contact(newContact);
            else
                std::cout << "All fields are required. Contact not added." << std::endl;
        }
        else if (command == "SEARCH")
        {
            std::string query;
            std::cout << "Enter search query (first name, last name, or nickname): ";
            std::getline(std::cin, query);
            phoneBook.search_contact(query);
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}