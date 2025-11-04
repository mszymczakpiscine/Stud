/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:10:15 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 18:10:15 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
    public:
        Fixed();
        Fixed(const int input);
        Fixed(const float input);
        Fixed(const Fixed &other);
        ~Fixed();

        Fixed &operator=(const Fixed &other);
        
        bool   operator>(const Fixed &other) const;
        bool   operator<(const Fixed &other) const;
        bool   operator>=(const Fixed &other) const;
        bool   operator<=(const Fixed &other) const;
        bool   operator==(const Fixed &other) const;
        bool   operator!=(const Fixed &other) const;

        Fixed  operator+(const Fixed &other) const;
        Fixed  operator-(const Fixed &other) const;
        Fixed  operator*(const Fixed &other) const;
        Fixed  operator/(const Fixed &other) const;
        
        Fixed  &operator++();    
        Fixed  operator++(int);    
        Fixed  &operator--();  
        Fixed  operator--(int);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        static Fixed &min(Fixed &a, Fixed &b);
        static const  Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const  Fixed &max(const Fixed &a, const Fixed &b);

    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif