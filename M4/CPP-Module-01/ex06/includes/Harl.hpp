/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:54:33 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 16:54:33 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

enum FilterLevel
{
    DEBUG = 0,
    INFO,
    WARNING,
    ERROR,
};

class HarlFilter
{
    public:
        HarlFilter();
        ~HarlFilter();
        void    complain(std::string level);
        int     filterLevel(std::string level);
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
        struct HarlInfo
        {
            std::string level;
            void    (HarlFilter::*func)(void);
        };
        HarlInfo _harlInfo[4];
};

#endif
