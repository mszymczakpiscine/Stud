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

#include <iostream>  // Pour std::cout (affichage)
#include <cctype>    // Pour std::toupper (conversion en majuscules)    
#include <string>    // Pour utiliser std::string

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
void PhoneBook::search_contact(const std::string& query) const
{
    bool found = false;
    for (int i = 0; i < current_index; ++i)
    {
        if (contacts[i].get_first_name() == query ||
            contacts[i].get_last_name() == query ||
            contacts[i].get_nickname() == query)
        {
            std::cout << "Index: " << i << std::endl;
            std::cout << "First Name: " << contacts[i].get_first_name() << std::endl;
            std::cout << "Last Name: " << contacts[i].get_last_name() << std::endl;
            std::cout << "Nickname: " << contacts[i].get_nickname() << std::endl;
            std::cout << "Phone Number: " << contacts[i].get_phone_number() << std::endl;
            std::cout << "Darkest Secret: " << contacts[i].get_darkest_secret() << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "No contact found with the given query." << std::endl;
}

PhoneBook::~PhoneBook()
{
}
