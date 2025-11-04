/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:22:05 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 16:22:05 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
    _harlInfo[0] = (HarlInfo){"DEBUG", &Harl::debug};
    _harlInfo[1] = (HarlInfo){"INFO", &Harl::info};
    _harlInfo[2] = (HarlInfo){"WARNING", &Harl::warning};
    _harlInfo[3] = (HarlInfo){"ERROR", &Harl::error};
    std::cout << "Harl created!" << std::endl;
}
Harl::~Harl()
{
    std::cout << "Harl destroyed!" << std::endl;
}
void   Harl::debug( void )
{
    std::cout << "      [DEBUG]"  << std::endl;
    std::cout << "Debug function called" << std::endl;
}
void    Harl::info( void )
{
    std::cout << "      [INFO]" << std::endl;
    std::cout << "Info function called" << std::endl;
}
void    Harl::warning( void )
{
    std::cout << "      [WARNING]" << std::endl;
    std::cout << "Warning function called" << std::endl;
}
void    Harl::error( void )
{
    std::cout << "      [ERROR]" << std::endl;
    std::cout << "Error function called" << std::endl;
}

void    Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (level == _harlInfo[i].level)
        {
            (this->*(_harlInfo[i].func))();
            return ;
        }
    }
}
