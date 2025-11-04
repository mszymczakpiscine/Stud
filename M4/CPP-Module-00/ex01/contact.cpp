/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:27:22 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/30 21:27:22 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}   

void    Contact::set_first_name(const std::string& str)
{
    this->first_name = str;
}
std::string Contact::get_first_name() const
{
    return this->first_name;
}

void    Contact::set_last_name(const std::string& str)
{
    this->last_name = str;
}
std::string Contact::get_last_name() const
{
    return this->last_name;
}
void    Contact::set_nickname(const std::string& str)
{
    this->nickname = str;
}
std::string Contact::get_nickname() const
{
    return this->nickname;
}

void    Contact::set_phone_number(const std::string& str)
{
    this->phone_number = str;
}
std::string Contact::get_phone_number() const
{
    return this->phone_number;
}

void    Contact::set_darkest_secret(const std::string& str)
{
    this->darkest_secret = str;
}

std::string Contact::get_darkest_secret() const
{
    return this->darkest_secret;
}

bool    Contact::is_valid() const
{
    return !this->first_name.empty() &&
           !this->last_name.empty() &&
           !this->nickname.empty() &&
           !this->phone_number.empty() &&
           !this->darkest_secret.empty();
}

Contact::~Contact()
{
}   
