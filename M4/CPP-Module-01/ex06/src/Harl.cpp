/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:56:28 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 16:56:28 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

HarlFilter::HarlFilter()
{
    _harlInfo[0] = (HarlInfo){"DEBUG", &HarlFilter::debug};
    _harlInfo[1] = (HarlInfo){"INFO", &HarlFilter::info};
    _harlInfo[2] = (HarlInfo){"WARNING", &HarlFilter::warning};
    _harlInfo[3] = (HarlInfo){"ERROR", &HarlFilter::error};
    std::cout << "HarlFilter created! Hello i'm HarlFilter\n" << std::endl;
}

HarlFilter::~HarlFilter()
{
    std::cout << "ARGGGGHHH HarlFilter destroyed!\n... Goodbye from HarlFilter\nI was happy to help you\n" << std::endl;
}
void   HarlFilter::debug( void )
{
    std::cout << "      [DEBUG]\nDebug function called\n"  << std::endl;
}
void    HarlFilter::info( void )
{
    std::cout << "      [INFO]\nInfo function called\n" << std::endl;
}
void    HarlFilter::warning( void )
{
    std::cout << "      [WARNING]\nWarning function called\n" << std::endl;
}
void    HarlFilter::error( void )
{
    std::cout << "      [ERROR]\nError function called\n" << std::endl;
}
int     HarlFilter::filterLevel(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (level == _harlInfo[i].level)
            return (i);
    }
    return (-1);
}

void    HarlFilter::complain(std::string level)
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
