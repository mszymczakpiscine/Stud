/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:27:23 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/30 21:27:23 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>  
#include <string>
#include <iomanip>
#include <sstream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_index(0), add_index(0)
{
}
void PhoneBook::print_field(const std::string& field) const
{
    if (field.length() > 10)
        std::cout << field.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << field;
}

void PhoneBook::add_contact(const Contact& contact)
{
    contacts[add_index] = contact;
    add_index = (add_index + 1) % 8;
    if (current_index < 8)
        current_index++;
}

void PhoneBook::search_contacts() const
{
    if (current_index == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < current_index; ++i)
    {
        std::cout << std::setw(10) << i << "|";
        print_field(contacts[i].get_first_name());
        std::cout << "|";
        print_field(contacts[i].get_last_name());
        std::cout << "|";
        print_field(contacts[i].get_nickname());
        std::cout << std::endl;
    }

    std::string input;
    std::cout << "Enter index to display: ";
    std::getline(std::cin, input);

    if (input.empty())
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::stringstream ss(input);
    int index;
    if (!(ss >> index))
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::string remainder;
    ss >> remainder;
    if (!remainder.empty())
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    if (index < 0 || index >= current_index)
    {
        std::cout << "Index out of range." << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}

PhoneBook::~PhoneBook()
{
}