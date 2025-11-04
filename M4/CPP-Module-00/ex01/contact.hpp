/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:27:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/30 21:27:49 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class Contact
{
private: 
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

public:
        Contact();
        
        void    set_first_name(const std::string& str);
        void    set_last_name(const std::string& str);
        void    set_nickname(const std::string& str);
        void    set_phone_number(const std::string& str);
        void    set_darkest_secret(const std::string& str);
        
        std::string get_first_name() const;
        std::string get_last_name() const;
        std::string get_nickname() const;
        std::string get_phone_number() const;
        std::string get_darkest_secret() const;
        
        bool    is_valid() const;
        ~Contact();
};  

#endif