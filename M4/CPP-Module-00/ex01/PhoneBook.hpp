/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:27:46 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/30 21:27:46 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int current_index;
    int add_index;
    void print_field(const std::string& field) const;

public:
    PhoneBook();
    void add_contact(const Contact& contact);
    void search_contacts() const;
    ~PhoneBook();
};

#endif